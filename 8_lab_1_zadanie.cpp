#include <iostream>
#include <fstream>

using namespace std;

const int MAX_SIZE = 100; // Максимальний розмір масиву

// Функція для обнулення локальних максимумів у масиві
void zeroLocalMax(int arr[], int size) {
    for (int i = 1; i < size - 1; ++i) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            arr[i] = 0;
        }
    }
}

int main() {
    int n;
    cout << "Enter the option number (n): ";
    cin >> n;

    // Читання вихідного масиву з файлу
    ifstream inputFile("array_in_" + to_string(n) + ".txt");
    if (!inputFile) {
        cerr << "Error opening file array_in_" << n << ".txt";
        return 1;
    }

    int arr[MAX_SIZE];
    int size = 0;
    while (inputFile >> arr[size] && size < MAX_SIZE) {
        size++;
    }
    inputFile.close();

    // Обробка масиву
    zeroLocalMax(arr, size);

    // Запис результатів у файл
    ofstream outputFile("array_out_" + to_string(n) + ".txt");
    if (!outputFile) {
        cerr << "Error opening file array_out_" << n << ".txt";
        return 1;
    }

    for (int i = 0; i < size; ++i) {
        outputFile << arr[i] << " ";
    }
    outputFile.close();

    cout << "The results were successfully written to the file array_out_" << n << ".txt" << endl;

    return 0;
}