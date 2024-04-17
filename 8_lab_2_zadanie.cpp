#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// Функція для введення матриці з файлу
void inputMatrixFromFile(int **matrix, int M, int N, string filename) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error opening file " << filename << endl;
        exit(1);
    }

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!(inputFile >> matrix[i][j])) {
                cerr << "There is not enough data in the file " << filename << endl;
                exit(1);
            }
        }
    }
    inputFile.close();
}

// Функція для виведення матриці у файл
void printMatrixToFile(int **matrix, int M, int N, string filename) {
    ofstream outputFile(filename, ios::app);
    if (!outputFile) {
        cerr << "Error opening file " << filename << endl;
        exit(1);
    }

    outputFile << "\n\nOUTPUT INFO:\nMatrix:\n";
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            outputFile << matrix[i][j] << " ";
        }
        outputFile << "\n";
    }
    outputFile.close();
}

// Функція для знаходження рядка з найбільшою сумою елементів
int findMaxSumRow(int **matrix, int M, int N) {
    int maxSum = 0;
    int maxRow = 0;
    for (int i = 0; i < M; ++i) {
        int sum = 0;
        for (int j = 0; j < N; ++j) {
            sum += matrix[i][j];
        }
        if (sum > maxSum) {
            maxSum = sum;
            maxRow = i;
        }
    }
    return maxRow;
}

int main() {
    string filename;
    int M, N;

    // Введення ім'я файлу та розмірів матриці
    cout << "Enter a file name: ";
    cin >> filename;
    cout << "Enter the number of rows: ";
    cin >> M;
    cout << "Enter the number of columns: ";
    cin >> N;

    int **matrix;

    // Виділення пам'яті для матриці
    matrix = new int*[M];
    for (int i = 0; i < M; ++i) {
        matrix[i] = new int[N];
    }

    // Введення матриці з файлу
    inputMatrixFromFile(matrix, M, N, filename);

    // Виведення матриці у файл
    printMatrixToFile(matrix, M, N, filename);

    // Пошук рядка з найбільшою сумою елементів
    int maxRow = findMaxSumRow(matrix, M, N);

    // Виведення результату
    ofstream outputFile(filename, ios::app);
    if (!outputFile) {
        cerr << "Error opening file " << filename << endl;
        exit(1);
    }

    int maxSum = 0;
    for (int j = 0; j < N; ++j) {
        maxSum += matrix[maxRow][j];
    }
    outputFile << "Number of the row with the largest sum of elements: " << maxRow + 1 << endl;
    outputFile << "Maximum sum: " << maxSum << endl;
    outputFile.close();

    // Звільнення пам'яті
    for (int i = 0; i < M; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
