#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int digitProduct(int num) {
    int product = 1;
    while (num > 0) {
        product *= num % 10;
        num /= 10;
    }
    return product;
}

int main() {
    int n;
    std::cout << "Введите количество чисел: ";
    std::cin >> n;
    std::vector<int> A(n);

    std::cout << "Введите числа: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> A[i];
    }

    std::vector<int> result;
    for (int num : A) {
        int prod = digitProduct(num);
        if (prod != 180) {
            result.push_back(num);
            if (std::to_string(num).front() == '1' && std::to_string(num).back() == '1') {
                result.push_back(num);
            }
        }
    }

    std::sort(result.begin(), result.end());
    result.erase(std::unique(result.begin(), result.end()), result.end());

    std::cout << "Результат: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    return 0;
}
