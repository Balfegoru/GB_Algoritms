#include <iostream>

// 1.Реализовать пузырьковую сортировку двумерного массива например, массив
// 1,9,2 5,7,6 4,3,8 должен на выходе стать 1,2,3 4,5,6 7,8,9

void BubleSort(int* array, int size) {
    int c;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (array[j] > array[j + 1]) {
                c = array[j + 1];
                array[j + 1] = array[j];
                array[j] = c;
            }
        }
    }
}

//3.Запросить у пользователя 11 чисел и записать их в последовательность П

//Функция вывода
void ArrayView(int* array, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << ",";
    }
    std::cout << std::endl;
}


int main() {

    const int size = 9;
    int array[size] = { 1, 9, 2, 5, 7, 6, 4, 3, 8 };


    std::cout << "1.Buble Sort" << std::endl;
    ArrayView(array, size);
    BubleSort(array, size);
    ArrayView(array, size);

    return 0;
}

