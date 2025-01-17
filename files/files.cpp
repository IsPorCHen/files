#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Baggage {
    int numItems;
    double weight;
};

int main() {
    setlocale(LC_ALL, "RU");
    ifstream inputFile("Bagazh.txt");

    if (!inputFile) {
        cerr << "Ошибка при открытии файла!" << endl;
        return 1;
    }

    vector<Baggage> passengers;

    Baggage baggage;
    while (inputFile >> baggage.numItems >> baggage.weight) {
        passengers.push_back(baggage);
    }

    inputFile.close();

    cout << "Пассажиры с багажом из одной вещи, вес которой меньше 5 кг:" << endl;
    for (const auto& passenger : passengers) {
        if (passenger.numItems == 1 && passenger.weight < 5.0) {
            cout << "Количество вещей: " << passenger.numItems
                << ", Вес: " << passenger.weight << " кг" << endl;
        }
    }

    return 0;
}
