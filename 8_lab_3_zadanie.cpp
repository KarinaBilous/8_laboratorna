#include <iostream>
#include <fstream>

using namespace std;

// Функція для сортування масиву вставкою за спаданням
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        /* Переміщення елементів масиву, які більше за key, на одну позицію вперед */
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Функція для зчитування масиву з файлу
void readArrayFromFile(const string& filename, int arr[], int& n) {
    ifstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < n; ++i) {
            file >> arr[i];
        }
        file.close();
    } else {
        cerr << "Unable to open file " << filename << endl;
    }
}

// Функція для виведення масиву в консоль
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    const string filename = "input.txt"; // Ім'я файлу з вхідними даними
    int n = 7; // Максимальний розмір масиву
    int arr[n];

    // Зчитування масиву з файлу
    readArrayFromFile(filename, arr, n);

    // Виведення вхідного масиву
    cout << "Input Array:" << endl;
    printArray(arr, n);

    // Сортування масиву вставкою за спаданням
    insertionSort(arr, n);

    // Виведення відсортованого масиву
    cout << "Sorted Array (Descending Order):" << endl;
    printArray(arr, n);

    return 0;
}