#include <iostream>
#include <clocale> 

void print_pyramid(const int* arr, int size) {
    std::cout << "Пирамида:\n";
    for (int i = 0; i < size; ++i) {
        int level = 0;
        int idx = i + 1;
        while (idx > 1) {
            idx >>= 1;
            ++level;
        }

        std::cout << level << " ";

        if (i == 0) {
            std::cout << "root";
        }
        else {
            int parent = (i - 1) / 2;
            if (i == 2 * parent + 1)
                std::cout << "left(" << arr[parent] << ")";
            else
                std::cout << "right(" << arr[parent] << ")";
        }

        std::cout << " " << arr[i] << "\n";
    }
}

int main() {

    std::setlocale(LC_ALL, "");

    int arr1[] = { 1, 3, 6, 5, 9, 8 };
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    std::cout << "Исходный массив: ";
    for (int i = 0; i < size1; ++i) std::cout << arr1[i] << " ";
    std::cout << "\n";
    print_pyramid(arr1, size1);
    std::cout << "\n";

    int arr2[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    std::cout << "Исходный массив: ";
    for (int i = 0; i < size2; ++i) std::cout << arr2[i] << " ";
    std::cout << "\n";
    print_pyramid(arr2, size2);
    std::cout << "\n";

    int arr3[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    std::cout << "Исходный массив: ";
    for (int i = 0; i < size3; ++i) std::cout << arr3[i] << " ";
    std::cout << "\n";
    print_pyramid(arr3, size3);

    return 0;
}
