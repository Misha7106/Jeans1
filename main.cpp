#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

vector<string> createTestData() {
    vector<string> data;
    data.push_back("Ñòðîêà 1 - òåñòîâûå äàííûå");
    data.push_back("Ñòðîêà 2 - äëÿ îòëàäêè ôóíêöèé");
    data.push_back("Ñòðîêà 3 - âûâîä íà ýêðàí");
    data.push_back("Ñòðîêà 4 - çàïèñü â ôàéë");
    data.push_back("Ñòðîêà 5 - êîíåö òåñòà");
    return data;
}

// Ôóíêöèÿ ¹ 1: ×òåíèå ñòðîê èç ôàéëà â âåêòîð
vector<string> readLinesFromFile(const string& filename) {
    vector<string> lines;


    ifstream File(filename);


    if (!File.is_open()) {
        cout << "Îøèáêà: íå óäàëîñü îòêðûòü ôàéë" << endl;
        return lines;
    }

    string line;
    while (getline(File, line)) {
        lines.push_back(line);
    }

    File.close();

    cout << "\n=== ÒÅÑÒÈÐÎÂÀÍÈÅ readLinesFromFile ===" << endl;
    cout << "Ôàéë: " << filename << endl;
    cout << "Ïðî÷èòàíî ñòðîê: " << lines.size() << endl;
    cout << "Ñîäåðæèìîå âåêòîðà:" << endl;

    if (lines.empty()) {
        cout << "  (âåêòîð ïóñò)" << endl;
    } else {
        for (size_t i = 0; i < lines.size(); ++i) {
            cout << "  [" << i << "] \"" << lines[i] << "\"" << endl;
        }
    }
    cout << "===================================\n" << endl;
    // === ÊÎÍÅÖ ÂÐÅÌÅÍÍÎÃÎ ÊÎÄÀ ===

    return lines;
}

// Ôóíêöèÿ ¹ 2: Âûâîä ñòðîê íà ýêðàí
void printLines(const vector<string>& lines) {
    if (lines.empty()) {
        cout << "Íåò äàííûõ äëÿ âûâîäà" << endl;
        return;
    }

    for (size_t i = 0; i < lines.size(); i++) {
        cout << lines[i] << endl;
    }
}

// Ôóíêöèÿ ¹ 3: Çàïèñü ñòðîê â ôàéë
void writeLinesToFile(const vector<string>& lines, const string& filename) {
    if (lines.empty()) {
        cerr << "Îøèáêà: âåêòîð ïóñò" << endl;
        return;
    }

    ofstream file(filename);
    if (!file) {
        cerr << "Îøèáêà îòêðûòèÿ ôàéëà: " << filename << endl;
        return;
    }

    for (size_t i = 0; i < lines.size(); i++) {
        file << lines[i] << endl;
    }

    file.close();
}

int main() {

    setlocale(LC_ALL, "Russian");
    // Ïîñëåäîâàòåëüíûé âûçîâ òðåõ ôóíêöèé
    string inputFilename = "input.txt";
    string outputFilename = "output.txt";

    // Âûçîâ ôóíêöèè ¹ 1
    vector<string> lines = readLinesFromFile(inputFilename);

    // Âûçîâ ôóíêöèè ¹ 2
    printLines(lines);

    // Âûçîâ ôóíêöèè ¹ 3
    writeLinesToFile(lines, outputFilename);

    return 0;
}
