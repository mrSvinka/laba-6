//3. 	Дана целочисленная матрица {Aij}i=1..n,j=1..m (n,m<=100). Найти строку, в которой меньше всего четных чисел, и заменить все      элементы этой строки их квадратами.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int n, m;
    cout << "Введите размер матрицы (n): ";
    cin >> n;
    cout << "Введите размер матрицы (m): ";
    cin >>m;
    vector<vector<int>> A(n, vector<int>(m));

    cout << "Введите элементы матрицы: ";
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < m; ++j) 
        {
            cin >> A[i][j];
        }
    }

    int minEvenCount = m + 1; // больше чем максимум
    int minRowIndex = -1;

    for (int i = 0; i < n; ++i) 
    {
        int evenCount = 0;
        for (int j = 0; j < m; ++j) 
        {
            if (A[i][j] % 2 == 0) evenCount++;
        }
        if (evenCount < minEvenCount) 
        {
            minEvenCount = evenCount;
            minRowIndex = i;
        }
    }

    for (int j = 0; j < m; ++j) 
    {
        A[minRowIndex][j] *= A[minRowIndex][j];
    }

    cout << "Матрица после изменения: \n";
    for (const auto& row : A) 
    {
        for (int val : row) 
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}

