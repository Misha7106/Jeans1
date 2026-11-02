<!-- ================= ШАПКА ================= -->
<div align="center">

  <!-- Замените ссылку на вашу картинку/логотип -->
  <img src="https://via.placeholder.com/150x150.png?text=LOGO" alt="Logo" width="120" height="120">

  <h1>Название вашего проекта</h1>

  <p>
    <strong>Краткое описание того, что делает ваш проект.</strong><br>
    Например: Утилита для обхода блокировок и ускорения соединения.
  </p>

  <!-- Бейджи (можно взять готовые на shields.io) -->
  <p>
    <img src="https://img.shields.io/badge/version-1.0.0-blue?style=for-the-badge" alt="Version">
    <img src="https://img.shields.io/badge/platform-Windows%20%7C%20Linux-lightgrey?style=for-the-badge" alt="Platform">
    <img src="https://img.shields.io/badge/license-MIT-green?style=for-the-badge" alt="License">
  </p>

  <!-- Быстрые ссылки -->
  <p>
    <a href="#установка">Установка</a> •
    <a href="#использование">Использование</a> •
    <a href="#faq">FAQ</a>
  </p>

</div>

<br>

<!-- ================= ПРЕДУПРЕЖДЕНИЕ (Алерт) ================= -->
<!-- GitHub автоматически стилизует этот блок -->
> [!CAUTION]
> **ВНИМАНИЕ: ФЕЙКИ**
> Я не веду другие страницы в Telegram. Если вы наткнулись на что-то вне этого репозитория — это подделка.
> **Скачивайте файлы только отсюда.**

<br>

<!-- ================= ВАЖНАЯ ИНФОРМАЦИЯ (Алерт) ================= -->
> [!IMPORTANT]
> **Проверка файлов**
> Все исполняемые файлы в папке `bin` взяты из оригинального источника. Проверяйте контрольные суммы перед запуском. Не используйте поисковики для скачивания — там часто предлагают вирусы.

<br>

<!-- ================= ОПИСАНИЕ ФАЙЛОВ (Карточки/Таблица) ================= -->
## 📂 Краткое описание файлов

Здесь мы используем HTML-таблицу, чтобы сделать список более аккуратным, чем стандартный Markdown.

<table>
  <thead>
    <tr>
      <th align="left">Файл</th>
      <th align="left">Описание</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>general.bat</code></td>
      <td>Запуск стратегии вручную. Используйте для проверки работоспособности.</td>
    </tr>
    <tr>
      <td><code>service.bat</code></td>
      <td>Установка в автозапуск и другие функции (см. ниже).</td>
    </tr>
  </tbody>
</table>

<br>

<!-- ================= СПИСОК С ПОДПУНКТАМИ ================= -->
### 🛠️ Функции <code>service.bat</code>

<ul>
  <li><strong><code>Install Service</code></strong> — установка любой стратегии в автозапуск (<code>services.msc</code>).</li>
  <li><strong><code>Remove Services</code></strong> — удаление стратегии и WinDivert из служб.</li>
  <li><strong><code>Check Status</code></strong> — проверка статуса обхода и служб.
    <ul>
      <li>Показывает, запущен ли <code>WinDivert</code>.</li>
    </ul>
  </li>
  <li><strong><code>Game Filter</code></strong> — переключение режима обхода для игр (UDP/TCP порты > 1023).
    <blockquote>
      <p><em>После переключения требуется перезапуск стратегии.</em></p>
    </blockquote>
  </li>
</ul>

<br>

<!-- ================= СПОЙЛЕР (Свернутый блок) ================= -->
<!-- Отлично подходит для длинных инструкций или логов -->
<details>
  <summary><b>▶ Нажмите, чтобы посмотреть пример лога ошибки (Спойлер)</b></summary>

  <br>

  ```bash
  [ERROR] WinDivert driver not found.
  [WARN] Trying to restart service...
  [INFO] Service restarted successfully.
