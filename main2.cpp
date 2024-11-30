/*2. 	Ввести последовательность натуральных чисел {Aj}j=1...n (n<=1000). Упорядочить последовательность по неубыванию произведения цифр числа, 
числа с одинаковыми произведениями цифр дополнительно упорядочить по неубыванию первой цифры числа, 
числа с одинаковыми произведениями цифр и одинаковыми первыми цифрами дополнительно упорядочить по неубыванию самого числа.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int digitProduct(int num) 
{
    int product = 1;
    while (num > 0) 
    {
        product *= num % 10;
        num /= 10;
    }
    return product;
}

int main() 
{
    int n;
    cout << "Введите количество чисел: ";
    cin >> n;
    vector<int> A(n);

    cout << "Введите числа: ";
    for (int i = 0; i < n; ++i) 
    {
        cin >> A[i];
    }

    sort(A.begin(), A.end(), [](int a, int b) {
        int prodA = digitProduct(a);
        int prodB = digitProduct(b);
        if (prodA != prodB) return prodA < prodB;
        int firstA = std::to_string(a)[0] - '0';
        int firstB = std::to_string(b)[0] - '0';
        return (firstA != firstB) ? firstA < firstB : a < b;
    });

    cout << "Упорядоченная последовательность: ";
    for (int num : A) 
    {
        cout << num << " ";
    }
    return 0;
}