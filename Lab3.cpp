#include <iostream>
#include <vector>
using namespace std;

struct Stats {
    double min, max, avg;
};

// 1. min, max and average of an array
Stats arrayStats(double arr[], int size) {
    Stats s = {arr[0], arr[0], 0};

    for (int i = 0; i < size; i++) {
        if (arr[i] < s.min) s.min = arr[i];
        if (arr[i] > s.max) s.max = arr[i];
        s.avg += arr[i];
    }
    s.avg /= size;
    return s;
}

// 2. span of a matrix (max - min)
double matrixSpan(vector<vector<double>> m, int rows, int cols) {
    double minVal = m[0][0], maxVal = m[0][0];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            if (m[i][j] < minVal) minVal = m[i][j];
            if (m[i][j] > maxVal) maxVal = m[i][j];
        }
    return maxVal - minVal;
}

// 3. i-th fibonacci number (F0 = 0, F1 = 1)
long long fib(int i) {
    long long a = 0, b = 1;

    for (int k = 0; k < i; k++) {
        long long next = a + b;
        a = b;
        b = next;
    }
    return a;
}

int main() {
    double arr[] = {3.5, -2, 7.25, 0, 4};
    Stats s = arrayStats(arr, 5);
    cout << "min = " << s.min << ", max = " << s.max << ", avg = " << s.avg << endl;

    vector<vector<double>> m = {{1, 2.5, -3, 4}, {0.5, 9, 2, 1}, {-1.5, 3, 6, 8.5}};
    cout << "span = " << matrixSpan(m, 3, 4) << endl;

    for (int i = 0; i <= 10; i++)
        cout << fib(i) << " ";
    cout << endl;

    return 0;
}
