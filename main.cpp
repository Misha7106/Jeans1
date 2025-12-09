#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

vector<string> createTestData() {
    vector<string> data;
    data.push_back("Строка 1 - тестовые данные");
    data.push_back("Строка 2 - для отладки функций");
    data.push_back("Строка 3 - вывод на экран");
    data.push_back("Строка 4 - запись в файл");
    data.push_back("Строка 5 - конец теста");
    return data;
}

// Функция № 1: Чтение строк из файла в вектор
vector<string> readLinesFromFile(const string& filename) {
    // Здесь будет код для чтения строк из файла
    vector<string> lines;
    // TODO: Реализовать чтение из файла
    return lines;
}

// Функция № 2: Вывод строк на экран
void printLines(const vector<string>& lines) {
    if (lines.empty()) {
        cout << "Нет данных для вывода" << endl;
        return;
    }

    for (size_t i = 0; i < lines.size(); i++) {
        cout << lines[i] << endl;
    }
}

// Функция № 3: Запись строк в файл
void writeLinesToFile(const vector<string>& lines, const string& filename) {
    if (lines.empty()) {
        cerr << "Ошибка: вектор пуст" << endl;
        return;
    }

    ofstream file(filename);
    if (!file) {
        cerr << "Ошибка открытия файла: " << filename << endl;
        return;
    }

    for (size_t i = 0; i < lines.size(); i++) {
        file << lines[i] << endl;
    }

    file.close();
}

int main() {

    setlocale(LC_ALL, "russian");
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
