<div align="center">

<h1>🛴 ДАНОН — распознавание номерных знаков электросамокатов</h1>

<p><strong>Консольное приложение для распознавания номерных знаков электросамокатов с фотографий.</strong></p>
<p>Реализует конвейер: <em>фото → предобработка (OpenCV) → OCR (Tesseract) → сохранение результата в SQLite</em>.</p>

<br>

<p>
  <img src="https://img.shields.io/badge/C%2B%2B-17-blue?logo=cplusplus&style=for-the-badge" alt="C++">
  <img src="https://img.shields.io/badge/OpenCV-4.x-green?logo=opencv&style=for-the-badge" alt="OpenCV">
  <img src="https://img.shields.io/badge/Tesseract-5.5.1-orange?style=for-the-badge" alt="Tesseract">
  <img src="https://img.shields.io/badge/SQLite-3.51.0-blue?style=for-the-badge" alt="SQLite">
  <img src="https://img.shields.io/badge/Platform-Windows%2010%2F11-lightgrey?style=for-the-badge" alt="Platform">
</p>

<p>
  <a href="#1-зависимости">Зависимости</a> •
  <a href="#2-установка-и-сборка">Сборка</a> •
  <a href="#3-запуск-и-использование">Запуск</a> •
  <a href="#4-структура-проекта">Структура</a> •
  <a href="#5-принцип-работы">Принцип работы</a>
</p>

</div>

<hr>

<blockquote>
  <p><strong>📌 Примечание:</strong> Курсовой проект, MVP 1. Подробное описание архитектуры и результатов тестирования — в отдельной документации и отчётах по спринтам.</p>
</blockquote>

<hr>

<h2>📋 Содержание</h2>
<ul>
  <li><a href="#1-зависимости">1. Зависимости</a></li>
  <li><a href="#2-установка-и-сборка">2. Установка и сборка</a></li>
  <li><a href="#3-запуск-и-использование">3. Запуск и использование</a></li>
  <li><a href="#4-структура-проекта">4. Структура проекта</a></li>
  <li><a href="#5-принцип-работы">5. Принцип работы</a></li>
  <li><a href="#6-особенности-и-ограничения-mvp-1">6. Особенности и ограничения (MVP 1)</a></li>
</ul>

<hr>

<h2 id="1-зависимости">1. Зависимости</h2>

<h3>1.1. Аппаратные требования</h3>
<table>
  <thead>
    <tr><th>Компонент</th><th>Требование</th></tr>
  </thead>
  <tbody>
    <tr><td><strong>Процессор</strong></td><td>x86_64</td></tr>
    <tr><td><strong>ОЗУ</strong></td><td>от 4 ГБ (рекомендуется 8 ГБ для обработки изображений)</td></tr>
    <tr><td><strong>Свободное место на диске</strong></td><td>от 500 МБ</td></tr>
  </tbody>
</table>

<h3>1.2. Программные требования</h3>
<table>
  <thead>
    <tr><th>Компонент</th><th>Версия</th><th>Назначение</th></tr>
  </thead>
  <tbody>
    <tr><td><strong>Windows</strong></td><td>10/11</td><td>Операционная система</td></tr>
    <tr><td><strong>Visual Studio Code</strong></td><td>1.70+</td><td>Среда разработки</td></tr>
    <tr><td><strong>CMake</strong></td><td>3.15+</td><td>Система сборки</td></tr>
    <tr><td><strong>MinGW-w64 (GCC)</strong></td><td>15.2.0+</td><td>Компилятор C++</td></tr>
    <tr><td><strong>MSYS2</strong></td><td>последняя</td><td>Менеджер пакетов</td></tr>
    <tr><td><strong>OpenCV</strong></td><td>4.x</td><td>Компьютерное зрение (обработка фото)</td></tr>
    <tr><td><strong>Tesseract OCR</strong></td><td>5.5.1</td><td>Движок распознавания текста</td></tr>
    <tr><td><strong>Leptonica</strong></td><td>1.86.0</td><td>Библиотека обработки изображений</td></tr>
    <tr><td><strong>SQLite3</strong></td><td>3.51.0</td><td>Библиотека базы данных</td></tr>
  </tbody>
</table>

<blockquote>
  <p><strong>⚠️ Важно:</strong> файл базы данных <code>recognition.db</code> создаётся в папке <code>data/</code>, путь к которой передаётся через макрос <code>DANON_DATA_DIR</code> в <code>CMakeLists.txt</code>.</p>
</blockquote>

<hr>

<h2 id="2-установка-и-сборка">2. Установка и сборка</h2>

<h3>2.1. Установка зависимостей</h3>
<p>Для работы проекта необходимо установить библиотеки через пакетный менеджер MSYS2. Откройте терминал <strong>MinGW64</strong> и выполните:</p>

<pre><code>pacman -S mingw-w64-x86_64-toolchain \
      mingw-w64-x86_64-cmake \
      mingw-w64-x86_64-opencv \
      mingw-w64-x86_64-tesseract \
      mingw-w64-x86_64-tesseract-data-eng \
      mingw-w64-x86_64-leptonica \
      mingw-w64-x86_64-sqlite3</code></pre>

<h3>2.2. Сборка проекта</h3>
<p>Откройте терминал в корневой папке проекта <code>danon</code> и выполните:</p>

<pre><code>mkdir build
cd build
cmake -G "MinGW Makefiles" ..
cmake --build . --config Release</code></pre>

<p>В результате в папке <code>build/</code> появится исполняемый файл <code>app.exe</code>.</p>

<blockquote>
  <p><strong>⚠️ Примечание:</strong> путь к папке <code>data/</code> фиксируется на этапе сборки через макрос <code>DANON_DATA_DIR</code>. Если вы переместите папку <code>data</code>, потребуется пересборка проекта.</p>
</blockquote>

<hr>

<h2 id="3-запуск-и-использование">3. Запуск и использование</h2>

<h3>3.1. Подготовка данных</h3>
<ol>
  <li>Поместите исходные изображения с самокатами (форматы <code>.jpg</code>, <code>.jpeg</code>, <code>.png</code>) в папку <code>data/</code>.</li>
  <li>Убедитесь, что в папке <code>tessdata/</code> находится файл языковой модели <code>eng.traineddata</code> (он устанавливается вместе с пакетом <code>mingw-w64-x86_64-tesseract-data-eng</code>).</li>
</ol>

<h3>3.2. Работа с консольным меню</h3>
<p>Запускать программу следует <strong>из папки <code>build/</code></strong> — путь к <code>tessdata</code> задан относительно рабочей директории.</p>
<p>После запуска <code>app.exe</code> открывается консольное меню:</p>

<table>
  <thead>
    <tr><th>Пункт меню</th><th>Действие</th></tr>
  </thead>
  <tbody>
    <tr><td><code>[1] ВЫБОР ФАЙЛА</code></td><td>Сканирует папку <code>data/</code> и выводит список доступных изображений для распознавания.</td></tr>
    <tr><td><code>[2] ИСТОРИЯ РАСПОЗНАВАНИЙ</code></td><td>Выводит все записи из БД <code>recognition.db</code> (от новых к старым). При ошибке чтения выводится сообщение.</td></tr>
    <tr><td><code>[3] ЗАВЕРШИТЬ РАБОТУ</code></td><td>Корректно завершает работу программы.</td></tr>
  </tbody>
</table>

<hr>

<h2 id="4-структура-проекта">4. Структура проекта</h2>

<h3>4.1. Описание папок и файлов</h3>
<table>
  <thead>
    <tr><th>Путь / Файл</th><th>Назначение</th></tr>
  </thead>
  <tbody>
    <tr><td><code>data/</code></td><td>Исходные изображения (<code>.jpg</code>, <code>.jpeg</code>, <code>.png</code>) и файл базы данных <code>recognition.db</code>.</td></tr>
    <tr><td><code>include/</code></td><td>Заголовочные файлы (<code>.h</code>, <code>.hpp</code>).</td></tr>
    <tr><td><code>libs/</code></td><td>Динамические библиотеки (<code>.dll</code>) для Windows (если используются для запуска).</td></tr>
    <tr><td><code>sql/</code></td><td>SQL-скрипты для создания и инициализации схемы базы данных.</td></tr>
    <tr><td><code>src/</code></td><td>Исходный код программы (<code>.cpp</code>).</td></tr>
    <tr><td><code>tessdata/</code></td><td>Языковые модели Tesseract OCR (файл <code>eng.traineddata</code>).</td></tr>
    <tr><td><code>tests/</code></td><td>Скрипты и файлы для юнит-тестирования.</td></tr>
    <tr><td><code>CMakeLists.txt</code></td><td>Главный файл конфигурации сборки (описание зависимостей).</td></tr>
  </tbody>
</table>

<h3>4.2. Исходный код (<code>src/</code>)</h3>
<table>
  <thead>
    <tr><th>Файл</th><th>Назначение</th></tr>
  </thead>
  <tbody>
    <tr><td><code>main.cpp</code></td><td>Точка входа в программу.</td></tr>
    <tr><td><code>menu.cpp</code></td><td>Реализация консольного интерфейса и навигации.</td></tr>
    <tr><td><code>image_preprocessor.cpp</code></td><td>Предобработка изображений (grayscale, CLAHE, бинаризация Оцу, инверсия).</td></tr>
    <tr><td><code>ocr_engine.cpp</code></td><td>Распознавание текста через Tesseract, а также дополнительная очистка (медианный фильтр, обрезка, масштабирование).</td></tr>
    <tr><td><code>database.cpp</code></td><td>Взаимодействие с базой данных SQLite.</td></tr>
    <tr><td><code>pipeline.cpp</code></td><td>Связующий модуль (соединяет предобработку, OCR и запись в БД).</td></tr>
  </tbody>
</table>

<hr>

<h2 id="5-принцип-работы">5. Принцип работы</h2>

<h3>5.1. Пайплайн обработки изображения</h3>
<ol>
  <li><strong>Выбор файла:</strong> пользователь выбирает изображение из папки <code>data/</code> через консольное меню.</li>
  <li><strong>Первичная предобработка (<code>ImagePreprocessor</code>):</strong>
    <ul>
      <li>изображение переводится в оттенки серого;</li>
      <li>применяется адаптивное выравнивание контраста (CLAHE);</li>
      <li>выполняется бинаризация (метод Оцу) и инверсия (если чёрного больше, чем белого).</li>
    </ul>
  </li>
  <li><strong>Дополнительная очистка (<code>OCREngine</code>):</strong>
    <ul>
      <li>удаляется шум (медианный фильтр);</li>
      <li>обрезаются белые края;</li>
      <li>выполняется масштабирование (если высота текста меньше 110 пикселей).</li>
    </ul>
  </li>
  <li><strong>Распознавание (Tesseract):</strong>
    <ul>
      <li>используется языковая модель <code>eng</code>;</li>
      <li>включён белый список символов: <code>0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ</code>;</li>
      <li>отключены встроенные словари (чтобы не было ложных исправлений);</li>
      <li>используется режим <code>PSM_SINGLE_LINE</code>; если распознано меньше 5 символов — включается резервный <code>PSM_RAW_LINE</code>;</li>
      <li>выполняется постобработка (замена похожих букв на цифры: <code>O→0</code>, <code>I→1</code> и т.д.).</li>
    </ul>
  </li>
  <li><strong>Сохранение (SQLite):</strong> распознанный текст и уверенность (<code>confidence</code>) записываются в таблицу базы данных <code>recognition.db</code>.</li>
</ol>

<h3>5.2. Схема базы данных (SQLite)</h3>
<p>Для хранения истории используется таблица <code>recognition_results</code>:</p>

<table>
  <thead>
    <tr><th>Поле (столбец)</th><th>Тип данных</th><th>Описание</th></tr>
  </thead>
  <tbody>
    <tr><td><code>id</code></td><td>INTEGER</td><td>Первичный ключ (<code>rowid</code>). Уникальный идентификатор записи.</td></tr>
    <tr><td><code>file_path</code></td><td>TEXT</td><td>Путь к исходному изображению.</td></tr>
    <tr><td><code>recognized_text</code></td><td>TEXT</td><td>Распознанный номер самоката.</td></tr>
    <tr><td><code>confidence</code></td><td>REAL</td><td>Уверенность OCR (от 0.0 до 1.0).</td></tr>
    <tr><td><code>created_at</code></td><td>TEXT</td><td>Дата и время добавления записи.</td></tr>
  </tbody>
</table>

<h3>5.3. Класс <code>Database</code> (работа с историей)</h3>
<p>Класс <code>Database</code> (описан в <code>include/database.h</code>) отвечает за все операции с SQLite.</p>

<table>
  <thead>
    <tr><th>Метод</th><th>Описание</th></tr>
  </thead>
  <tbody>
    <tr><td><code>getHistory(int limit = -1)</code></td><td>Возвращает историю распознаваний. При значении <code>-1</code> (по умолчанию) извлекаются все записи. Если передать положительное число — вернёт только последние N записей. Запрос сортирует данные по <code>id DESC</code> (от новых к старым).</td></tr>
    <tr><td><code>lastError()</code></td><td>Возвращает строку с текстом последней ошибки. Если операция прошла успешно — возвращает пустую строку.</td></tr>
  </tbody>
</table>

<hr>

<h2 id="6-особенности-и-ограничения-mvp-1">6. Особенности и ограничения (MVP 1)</h2>
<ul>
  <li><strong>Проблема с OpenCV:</strong> в файле <code>ocr_engine.cpp</code> строку <code>#include &lt;opencv2/geometry.hpp&gt;</code> необходимо закомментировать, если она выдаёт ошибку, так как в некоторых сборках OpenCV этот заголовок отсутствует.</li>
  <li><strong>Путь к <code>tessdata</code>:</strong> в коде инициализации Tesseract путь задан как <code>"../tessdata"</code>. Запускайте программу из папки <code>build/</code>, чтобы путь был корректен, или измените его на абсолютный.</li>
  <li><strong>Качество фото:</strong> Tesseract чувствителен к размытию, наклонам и теням. Чем чётче и контрастнее номер на фото, тем выше точность.</li>
</ul>

<hr>

<div align="center">
  <sub>Сделано с ❤️ для курсового проекта · MVP 1</sub>
</div>
