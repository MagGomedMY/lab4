#pragma once
#include <iostream>

class IntVector {
private:
    int* data;      // Указатель на динамический массив
    int size;       // Текущий размер
    int capacity;   // Выделенная ёмкость

public:
    // Конструкторы
    IntVector();                        // По умолчанию
    IntVector(int n);                   // С параметром (размер)
    
    // Правило трёх
    IntVector(const IntVector& other);  // Конструктор копирования
    ~IntVector();                       // Деструктор
    IntVector& operator=(const IntVector& other); // Оператор присваивания

    // Базовые методы (нужны для работы)
    void pushBack(int value);
    int getSize() const { return size; }
    int getCapacity() const { return capacity; }
    void print() const;

    // --- Дополнительная функциональность (Вариант 4) ---
    bool isSorted() const; // Проверка на упорядоченность (по возрастанию)
    IntVector merge(const IntVector& other) const; // Слияние двух отсортированных векторов
};