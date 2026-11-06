#include "IntVector.h"
#include <stdexcept>

// Конструктор по умолчанию
IntVector::IntVector() : size(0), capacity(10) {
    data = new int[capacity];
}

// Конструктор с размером
IntVector::IntVector(int n) : size(n), capacity(n > 0 ? n : 1) {
    if (n < 0) {
        throw std::invalid_argument("Размер не может быть отрицательным");
    }
    data = new int[capacity];
    for (int i = 0; i < size; ++i) {
        data[i] = 0; 
    }
}

// Конструктор копирования (глубокое копирование)
IntVector::IntVector(const IntVector& other) : size(other.size), capacity(other.capacity) {
    data = new int[capacity];
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

// Деструктор
IntVector::~IntVector() {
    delete[] data;
}

// Оператор присваивания
IntVector& IntVector::operator=(const IntVector& other) {
    if (this != &other) {
        int* newData = new int[other.capacity];
        for (int i = 0; i < other.size; ++i) {
            newData[i] = other.data[i];
        }
        delete[] data;
        data = newData;
        size = other.size;
        capacity = other.capacity;
    }
    return *this;
}

// Добавление в конец
void IntVector::pushBack(int value) {
    if (size >= capacity) {
        int newCapacity = capacity * 2;
        int* newData = new int[newCapacity];
        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
    data[size] = value;
    size++;
}

// Вывод на экран
void IntVector::print() const {
    std::cout << "[";
    for (int i = 0; i < size; ++i) {
        std::cout << data[i];
        if (i < size - 1) std::cout << ", ";
    }
    std::cout << "]\n";
}

// --- Дополнительная функциональность (Вариант 4) ---

// Проверка, отсортирован ли вектор по возрастанию
bool IntVector::isSorted() const {
    for (int i = 0; i < size - 1; ++i) {
        if (data[i] > data[i + 1]) {
            return false;
        }
    }
    return true;
}

// Слияние двух отсортированных векторов
IntVector IntVector::merge(const IntVector& other) const {
    // Предполагаем, что оба вектора отсортированы.
    IntVector result;
    
    int i = 0; // Индекс для текущего вектора
    int j = 0; // Индекс для other

    // Сливаем два массива
    while (i < size && j < other.size) {
        if (data[i] <= other.data[j]) {
            result.pushBack(data[i]);
            i++;
        } else {
            result.pushBack(other.data[j]);
            j++;
        }
    }

    // Добавляем остатки из первого
    while (i < size) {
        result.pushBack(data[i]);
        i++;
    }

    // Добавляем остатки из второго
    while (j < other.size) {
        result.pushBack(other.data[j]);
        j++;
    }

    return result;
}