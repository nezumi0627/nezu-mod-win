// ==WindhawkMod==
// @id              taskbar-clock
// @name            Taskbar Clock Customizer
// @description     タスクバーの時計表示をカスタマイズします
// @version         0.3
// @author          nezumi0627
// @include         explorer.exe
// ==/WindhawkMod==

// ==WindhawkModReadme==
/*
# Taskbar Clock Customizer

タスクバーの時計表示をカスタマイズします。

## 機能
- 時計の表示形式を変更（モダンなデザイン）
- 時計の表示範囲を拡大
- 曜日をカラフルな絵文字で表示

## 技術詳細
- Windows APIフックを使用してタスクバーの時計表示をカスタマイズ
- エラー処理と型安全性を重視
- モジュール化された設計
*/
// ==/WindhawkModReadme==

#include <windows.h>
#include <cwchar>
#include <winuser.h>
#include "windhawk_api.h"

namespace {
    // ウィンドウサイズ調整用の定数
    struct WindowSizeConstants {
        static const double CLOCK_HEIGHT_MULTIPLIER = 2.5;
        static const int CLOCK_WIDTH_MULTIPLIER = 12;
        static const int MAX_CLASSNAME_LENGTH = 256;
        static const int DEFAULT_TIME_BUFFER = 32;
    };

    // 曜日表示用の絵文字配列
    struct WeekdayEmojis {
        static constexpr const wchar_t* EMOJIS[] = {
            L"🌞",  // Sunday
            L"🌙",  // Monday
            L"🔥",  // Tuesday
            L"💧",  // Wednesday
            L"🌿",  // Thursday
            L"⭐",  // Friday
            L"🌈"   // Saturday
        };
    };

    // 関数型定義
    using GetTimeFormatEx_t = int (WINAPI*)(LPCWSTR, DWORD, const SYSTEMTIME*, LPCWSTR, LPWSTR, int);
    using GetDateFormatEx_t = int (WINAPI*)(LPCWSTR, DWORD, const SYSTEMTIME*, LPCWSTR, LPWSTR, int, LPCWSTR);
    using GetWindowRect_t = BOOL (WINAPI*)(HWND, LPRECT);
    using SetWindowPos_t = BOOL (WINAPI*)(HWND, HWND, int, int, int, int, UINT);

    // オリジナル関数のポインタ
    struct OriginalFunctions {
        static GetTimeFormatEx_t GetTimeFormatEx;
        static GetDateFormatEx_t GetDateFormatEx;
        static GetWindowRect_t GetWindowRect;
        static SetWindowPos_t SetWindowPos;
    };

    // 静的メンバの初期化
    GetTimeFormatEx_t OriginalFunctions::GetTimeFormatEx = nullptr;
    GetDateFormatEx_t OriginalFunctions::GetDateFormatEx = nullptr;
    GetWindowRect_t OriginalFunctions::GetWindowRect = nullptr;
    SetWindowPos_t OriginalFunctions::SetWindowPos = nullptr;

    // ユーティリティ関数
    class WindowUtils {
    public:
        static bool IsPrimaryMonitorTaskbar(HWND hWnd) {
            HWND taskbar = GetAncestor(hWnd, GA_ROOT);
            MONITORINFO mi = { sizeof(MONITORINFO) };
            HMONITOR monitor = MonitorFromWindow(taskbar, MONITOR_DEFAULTTOPRIMARY);
            
            if (!GetMonitorInfoW(monitor, &mi)) {
                return false;
            }
            
            return (mi.dwFlags & MONITORINFO_PRIMARY) != 0;
        }

        static bool IsClockButtonWindow(HWND hWnd) {
            WCHAR className[WindowSizeConstants::MAX_CLASSNAME_LENGTH];
            if (!GetClassNameW(hWnd, className, ARRAYSIZE(className))) {
                return false;
            }
            return wcsstr(className, L"ClockButton") != nullptr;
        }
    };
}

// フック関数 - ウィンドウサイズ取得
BOOL WINAPI GetWindowRect_Hook(HWND hWnd, LPRECT lpRect) {
    if (!WindowUtils::IsClockButtonWindow(hWnd) || !WindowUtils::IsPrimaryMonitorTaskbar(hWnd)) {
        return OriginalFunctions::GetWindowRect(hWnd, lpRect);
    }

    BOOL result = OriginalFunctions::GetWindowRect(hWnd, lpRect);
    if (result) {
        int width = lpRect->right - lpRect->left;
        int height = lpRect->bottom - lpRect->top;
        lpRect->right = lpRect->left + (width * WindowSizeConstants::CLOCK_WIDTH_MULTIPLIER);
        lpRect->bottom = lpRect->top + static_cast<int>(height * WindowSizeConstants::CLOCK_HEIGHT_MULTIPLIER);
    }
    return result;
}

// フック関数 - ウィンドウ位置設定
BOOL WINAPI SetWindowPos_Hook(HWND hWnd, HWND hWndInsertAfter, int X, int Y, int cx, int cy, UINT uFlags) {
    if (WindowUtils::IsClockButtonWindow(hWnd) && WindowUtils::IsPrimaryMonitorTaskbar(hWnd)) {
        cx *= WindowSizeConstants::CLOCK_WIDTH_MULTIPLIER;
        cy = static_cast<int>(cy * WindowSizeConstants::CLOCK_HEIGHT_MULTIPLIER);
    }
    return OriginalFunctions::SetWindowPos(hWnd, hWndInsertAfter, X, Y, cx, cy, uFlags);
}

// フック関数 - 時刻フォーマット
int WINAPI GetTimeFormatEx_Hook(
    LPCWSTR lpLocaleName,
    DWORD dwFlags,
    const SYSTEMTIME* lpTime,
    LPCWSTR lpFormat,
    LPWSTR lpTimeStr,
    int cchTime) 
{
    if (!cchTime) {
        return WindowSizeConstants::DEFAULT_TIME_BUFFER;
    }

    if (!lpTime) {
        return OriginalFunctions::GetTimeFormatEx(lpLocaleName, dwFlags, lpTime, lpFormat, lpTimeStr, cchTime);
    }

    swprintf_s(lpTimeStr, cchTime, L"⚡%02d∶%02d⚡", 
        lpTime->wHour,
        lpTime->wMinute);

    return wcslen(lpTimeStr) + 1;
}

// フック関数 - 日付フォーマット
int WINAPI GetDateFormatEx_Hook(
    LPCWSTR lpLocaleName,
    DWORD dwFlags,
    const SYSTEMTIME* lpDate,
    LPCWSTR lpFormat,
    LPWSTR lpDateStr,
    int cchDate,
    LPCWSTR lpCalendar)
{
    if (!cchDate) {
        return WindowSizeConstants::DEFAULT_TIME_BUFFER;
    }

    if (!lpDate) {
        return OriginalFunctions::GetDateFormatEx(lpLocaleName, dwFlags, lpDate, lpFormat, lpDateStr, cchDate, lpCalendar);
    }

    swprintf_s(lpDateStr, cchDate, L"『%04d-%02d-%02d』%s", 
        lpDate->wYear,
        lpDate->wMonth,
        lpDate->wDay,
        WeekdayEmojis::EMOJIS[lpDate->wDayOfWeek]);

    return wcslen(lpDateStr) + 1;
}

// モジュール初期化
BOOL Wh_ModInit() {
    HMODULE user32 = GetModuleHandleW(L"user32.dll");
    HMODULE kernel32 = GetModuleHandleW(L"kernel32.dll");

    if (!user32 || !kernel32) {
        return FALSE;
    }

    // 関数アドレスの取得と検証
    auto getWindowRect = GetProcAddress(user32, "GetWindowRect");
    auto setWindowPos = GetProcAddress(user32, "SetWindowPos");
    auto getTimeFormatEx = GetProcAddress(kernel32, "GetTimeFormatEx");
    auto getDateFormatEx = GetProcAddress(kernel32, "GetDateFormatEx");

    if (!getWindowRect || !setWindowPos || !getTimeFormatEx || !getDateFormatEx) {
        return FALSE;
    }

    // フック設定
    Wh_SetFunctionHook((void*)getWindowRect, (void*)GetWindowRect_Hook, (void**)&OriginalFunctions::GetWindowRect);
    Wh_SetFunctionHook((void*)setWindowPos, (void*)SetWindowPos_Hook, (void**)&OriginalFunctions::SetWindowPos);
    Wh_SetFunctionHook((void*)getTimeFormatEx, (void*)GetTimeFormatEx_Hook, (void**)&OriginalFunctions::GetTimeFormatEx);
    Wh_SetFunctionHook((void*)getDateFormatEx, (void*)GetDateFormatEx_Hook, (void**)&OriginalFunctions::GetDateFormatEx);

    return TRUE;
}

void Wh_ModUninit() {
    // クリーンアップ処理は不要
}

void Wh_ModSettingsChanged() {
    // 将来的な設定変更機能のため
} 