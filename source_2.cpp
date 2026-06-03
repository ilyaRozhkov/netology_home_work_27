#include <iostream>
#include <clocale> 
#include <string>
#include <cmath>

int get_level(int index) {
    int level = 0;
    int idx = index + 1;
    while (idx > 1) {
        idx >>= 1;
        ++level;
    }
    return level;
}

void print_element(const int* arr, int index) {
    int level = get_level(index);
    std::cout << level << " ";
    if (index == 0) {
        std::cout << "root";
    }
    else {
        int parent = (index - 1) / 2;
        if (index == 2 * parent + 1)
            std::cout << "left(" << arr[parent] << ")";
        else
            std::cout << "right(" << arr[parent] << ")";
    }
    std::cout << " " << arr[index] << std::endl;
}

void print_pyramid(const int* arr, int size) {
    std::cout << "Пирамида:\n";
    for (int i = 0; i < size; ++i) {
        print_element(arr, i);
    }
}

int main() {

    std::setlocale(LC_ALL, "");

    std::cout << "Выберите пирамиду (1, 2 или 3):\n";
    std::cout << "1: 1 3 6 5 9 8\n";
    std::cout << "2: 94 67 18 44 55 12 6 42\n";
    std::cout << "3: 16 11 9 10 5 6 8 1 2 4\n";
    int choice;
    std::cin >> choice;

    const int* arr;
    int size;
    static int arr1[] = { 1, 3, 6, 5, 9, 8 };
    static int arr2[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
    static int arr3[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };

    switch (choice) {
    case 1: arr = arr1; size = sizeof(arr1) / sizeof(arr1[0]); break;
    case 2: arr = arr2; size = sizeof(arr2) / sizeof(arr2[0]); break;
    case 3: arr = arr3; size = sizeof(arr3) / sizeof(arr3[0]); break;
    default: std::cout << "Неверный выбор, берём пирамиду 1\n";
        arr = arr1; size = sizeof(arr1) / sizeof(arr1[0]); break;
    }

    std::cout << "Исходный массив: ";
    for (int i = 0; i < size; ++i) std::cout << arr[i] << " ";
    std::cout << "\n";

    print_pyramid(arr, size);

    int current = 0;
    std::string command;

    while (true) {
        std::cout << "Вы находитесь здесь: ";
        print_element(arr, current);
        std::cout << "Введите команду: ";
        std::cin >> command;

        if (command == "exit") {
            break;
        }
        else if (command == "up") {
            if (current == 0) {
                std::cout << "Ошибка! Отсутствует родитель\n";
            }
            else {
                current = (current - 1) / 2;
                std::cout << "Ок\n";
            }
        }
        else if (command == "left") {
            int left = 2 * current + 1;
            if (left >= size) {
                std::cout << "Ошибка! Отсутствует левый потомок\n";
            }
            else {
                current = left;
                std::cout << "Ок\n";
            }
        }
        else if (command == "right") {
            int right = 2 * current + 2;
            if (right >= size) {
                std::cout << "Ошибка! Отсутствует правый потомок\n";
            }
            else {
                current = right;
                std::cout << "Ок\n";
            }
        }
        else {
            std::cout << "Ошибка! Неизвестная команда\n";
        }
    }

    return 0;
}
