#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Функция № 1: Чтение строк из файла в вектор
vector<string> readLinesFromFile(const string& filename) {
    vector<string> lines;


    ifstream File(filename);


    if (!File.is_open()) {
        cout << "Ошибка: не удалось открыть файл" << endl;
        return lines;
    }

    string line;
    while (getline(File, line)) {
        lines.push_back(line);
    }

    File.close();

    cout << "\n=== ТЕСТИРОВАНИЕ readLinesFromFile ===" << endl;
    cout << "Файл: " << filename << endl;
    cout << "Прочитано строк: " << lines.size() << endl;
    cout << "Содержимое вектора:" << endl;

    if (lines.empty()) {
        cout << "  (вектор пуст)" << endl;
    } else {
        for (size_t i = 0; i < lines.size(); ++i) {
            cout << "  [" << i << "] \"" << lines[i] << "\"" << endl;
        }
    }
    cout << "===================================\n" << endl;
    // === КОНЕЦ ВРЕМЕННОГО КОДА ===

    return lines;
}

// Функция № 2: Вывод строк на экран
void printLines(const vector<string>& lines) {
    // Здесь будет код для вывода строк на экран
    // TODO: Реализовать вывод на экран
}

// Функция № 3: Запись строк в файл
void writeLinesToFile(const vector<string>& lines, const string& filename) {
    // Здесь будет код для записи строк в файл
    // TODO: Реализовать запись в файл
}

int main() {
    setlocale(LC_ALL, "Russian");
    // Последовательный вызов трех функций
    string inputFilename = "input.txt";
    string outputFilename = "output.txt";

    // Вызов функции № 1
    vector<string> lines = readLinesFromFile(inputFilename);

    // Вызов функции № 2
    printLines(lines);

    // Вызов функции № 3
    writeLinesToFile(lines, outputFilename);

    return 0;
}
