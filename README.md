# Nezu Mod Collection

<div align="center">
  <img src="docs/assets/logo.svg" alt="Nezu Mod Collection" width="800">
  
  <h3>
    Windows体験をより快適にするカスタマイズツール
  </h3>
  <p>
    <sub>モダンで美しいデザインのWindows拡張コレクション</sub>
  </p>

  <p align="center">
    <a href="https://github.com/ramensoftware/windhawk">
      <img src="https://img.shields.io/badge/Powered%20by-Windhawk-00a2ed?style=for-the-badge&logo=windows11&logoColor=white" alt="Powered by Windhawk">
    </a>
    <a href="#-システム要件">
      <img src="https://img.shields.io/badge/Windows%2011-00a2ed?style=for-the-badge&logo=windows11&logoColor=white" alt="Windows 11">
    </a>
    <a href="#-開発ガイド">
      <img src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++">
    </a>
  </p>

  <p align="center">
    <a href="#-機能">
      <img src="https://img.shields.io/badge/✨_機能-2196f3?style=for-the-badge" alt="Features">
    </a>
    <a href="#-インストール">
      <img src="https://img.shields.io/badge/📥_インストール-4caf50?style=for-the-badge" alt="Install">
    </a>
    <a href="#-開発">
      <img src="https://img.shields.io/badge/🛠️_開発-ff9800?style=for-the-badge" alt="Development">
    </a>
    <a href="#-コミュニティ">
      <img src="https://img.shields.io/badge/🤝_コミュニティ-9c27b0?style=for-the-badge" alt="Community">
    </a>
  </p>
</div>

## ✨ 機能

<div align="center" style="display: flex; justify-content: center; flex-wrap: wrap; gap: 20px; padding: 20px;">
  <div style="background: #ffffff0d; border-radius: 12px; padding: 24px; width: 320px; text-align: center; backdrop-filter: blur(8px); border: 1px solid #ffffff1a;">
    <a href="docs/taskbar-clock.md" style="text-decoration: none; color: inherit;">
      <div style="margin-bottom: 16px;">
        <img src="docs/assets/clock-icon.svg" alt="Clock Icon" width="80" style="border-radius: 16px;">
      </div>
      <h3 style="margin: 0 0 8px 0; color: #fff;">タスクバーの時計</h3>
      <div style="margin: 16px 0;">
        <img src="https://img.shields.io/badge/安定版-00c853?style=for-the-badge&logo=checkmarx&logoColor=white" alt="Stable">
      </div>
      <p style="color: #ffffffcc; margin: 0; font-size: 0.9em;">
        スタイリッシュな時計���日付表示を実現。<br>
        Windowsに自然に溶け込むモダンなデザイン。
      </p>
    </a>
  </div>
</div>

## 📥 インストール

<div align="center" style="padding: 20px;">
  <!-- シットアップ手順 -->
  <div style="background: #ffffff0d; border-radius: 12px; padding: 24px; margin-bottom: 24px; backdrop-filter: blur(8px); border: 1px solid #ffffff1a;">
    <h3 style="margin: 0 0 16px 0; color: #fff;">🔧 セットアップ手順</h3>
    <div style="text-align: left; color: #ffffffcc;">
      <ol style="margin: 0; padding-left: 24px;">
        <li style="margin-bottom: 12px;">
          <a href="https://github.com/ramensoftware/windhawk" style="color: #00a2ed; text-decoration: none;">Windhawk</a>をインストール
        </li>
        <li style="margin-bottom: 12px;">Windhawkを起動</li>
        <li style="margin-bottom: 12px;">「新しいModを作成」を選択</li>
        <li style="margin-bottom: 12px;">Modのソースコードをコピー</li>
        <li style="margin-bottom: 12px;">Windhawkエディタに貼り付け</li>
        <li style="margin-bottom: 12px;">「Compile Mod」をクリック</li>
        <li style="margin-bottom: 12px;">「Enable Mod」をクリック</li>
      </ol>
    </div>
  </div>

  <!-- 注意事項 -->
  <div style="background: #ff98000d; border-radius: 12px; padding: 24px; backdrop-filter: blur(8px); border: 1px solid #ff98001a;">
    <h3 style="margin: 0 0 16px 0; color: #fff;">⚠️ 注意事項</h3>
    <ul style="text-align: left; color: #ffffffcc; margin: 0; padding-left: 24px;">
      <li style="margin-bottom: 8px;">Windows 11での動作を前提に開発しています。Windows 10以前のOSでの動作は未確認のため、自己責任でご利用ください</li>
      <li style="margin-bottom: 8px;">無効化する場合は、Modのトグルをオフにしてください</li>
      <li style="margin-bottom: 8px;">一部の機能ではシステムの再起動が必要な場合があります</li>
    </ul>
  </div>
</div>

## 🛠️ 開発

<div align="center" style="padding: 20px;">
  <!-- アーキテクチャ -->
  <div style="background: #ffffff0d; border-radius: 12px; padding: 24px; margin-bottom: 24px; backdrop-filter: blur(8px); border: 1px solid #ffffff1a;">
    <h3 style="margin: 0 0 16px 0; color: #fff;">🏗️ アーキテクチャ</h3>
    <img src="docs/assets/architecture.svg" alt="Architecture" width="800" style="margin-bottom: 16px; border-radius: 8px;">
  </div>

  <!-- 開発基準 -->
  <div style="background: #ffffff0d; border-radius: 12px; padding: 24px; backdrop-filter: blur(8px); border: 1px solid #ffffff1a;">
    <h3 style="margin: 0 0 24px 0; color: #fff;">📋 開発基準</h3>
    <div style="display: grid; grid-template-columns: repeat(auto-fit, minmax(250px, 1fr)); gap: 16px;">
      <!-- コード品質 -->
      <div style="background: #ffffff05; border-radius: 8px; padding: 20px;">
        <h4 style="margin: 0 0 16px 0; color: #fff;">
          <span style="font-size: 1.2em; margin-right: 8px;">🎯</span>
          コード品質
        </h4>
        <ul style="color: #ffffffcc; margin: 0; padding-left: 20px; list-style-type: '→ ';">
          <li style="margin-bottom: 8px;">クリーンで保守性の高いコード作成</li>
          <li style="margin-bottom: 8px;">詳細ドキュメント整備</li>
          <li style="margin-bottom: 8px;">堅牢なエラー処理の実装</li>
        </ul>
      </div>
      <!-- アーキテクチャ -->
      <div style="background: #ffffff05; border-radius: 8px; padding: 20px;">
        <h4 style="margin: 0 0 16px 0; color: #fff;">
          <span style="font-size: 1.2em; margin-right: 8px;">🏗️</span>
          アーキテクチャ
        </h4>
        <ul style="color: #ffffffcc; margin: 0; padding-left: 20px; list-style-type: '→ ';">
          <li style="margin-bottom: 8px;">モジュール化された設計</li>
          <li style="margin-bottom: 8px;">再利用可能なコンポーネント</li>
          <li style="margin-bottom: 8px;">パフォーマンスの最適化</li>
        </ul>
      </div>
      <!-- セキュリティ -->
      <div style="background: #ffffff05; border-radius: 8px; padding: 20px;">
        <h4 style="margin: 0 0 16px 0; color: #fff;">
          <span style="font-size: 1.2em; margin-right: 8px;">🔒</span>
          セキュリティ
        </h4>
        <ul style="color: #ffffffcc; margin: 0; padding-left: 20px; list-style-type: '→ ';">
          <li style="margin-bottom: 8px;">安全なAPI使用</li>
          <li style="margin-bottom: 8px;">適切なメモリ管理</li>
          <li style="margin-bottom: 8px;">包括的なエラー対策</li>
        </ul>
      </div>
    </div>
  </div>
</div>

## 🤝 コミュニティ

<div align="center">
  <a href="../../issues">
    <img src="https://img.shields.io/badge/問題報告-e53935?style=for-the-badge&logo=github&logoColor=white" alt="Issues">
  </a>
  <a href="../../issues">
    <img src="https://img.shields.io/badge/機能提案-2196f3?style=for-the-badge&logo=github&logoColor=white" alt="Features">
  </a>
  <a href="../../pulls">
    <img src="https://img.shields.io/badge/プルリクエスト-4caf50?style=for-the-badge&logo=github&logoColor=white" alt="Pull Requests">
  </a>
</div>

## 📄 ライセンス

<div align="center">
  <a href="LICENSE">
    <img src="https://img.shields.io/badge/License-MIT-2196f3?style=for-the-badge&logo=opensourceinitiative&logoColor=white" alt="MIT License">
  </a>
</div>

---

<div align="center">
  <p>
    <sub>Created with ❤️ by <a href="https://github.com/nezumi0627">nezumi0627</a></sub>
  </p>
</div> 