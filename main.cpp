#include <iostream>
#include <windows.h>
#include "IntVector.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "=== Лабораторная работа №4. Средний уровень. Вариант 4 ===\n\n";

    // 1. Создаем два отсортированных вектора
    IntVector v1;
    v1.pushBack(1);
    v1.pushBack(3);
    v1.pushBack(5);
    
    IntVector v2;
    v2.pushBack(2);
    v2.pushBack(4);
    v2.pushBack(6);

    std::cout << "Вектор 1: "; v1.print();
    std::cout << "Вектор 2: "; v2.print();

    // 2. Проверка на отсортированность
    std::cout << "\nВектор 1 отсортирован? " << (v1.isSorted() ? "Да" : "Нет") << "\n";
    
    // Сломаем сортировку в v1 для проверки
    IntVector v3 = v1;
    v3 = v2; // Используем оператор присваивания
    v3.pushBack(0); // Теперь [2, 4, 6, 0] - не отсортирован
    std::cout << "Вектор 3: "; v3.print();
    std::cout << "Вектор 3 отсортирован? " << (v3.isSorted() ? "Да" : "Нет") << "\n";

    // 3. Слияние
    std::cout << "\nСлияние Вектора 1 и Вектора 2:\n";
    IntVector merged = v1.merge(v2);
    merged.print();

    // 4. Проверка глубокого копирования
    std::cout << "\nПроверка глубокого копирования:\n";
    IntVector copy = merged;
    std::cout << "Копия: "; copy.print();
    std::cout << "Меняем Копию (добавляем 100)...\n";
    copy.pushBack(100);
    std::cout << "Копия после изменения: "; copy.print();
    std::cout << "Оригинал merged: "; merged.print();
    std::cout << "(Оригинал не изменился - глубокое копирование работает!)\n";

    std::cout << "\n=== Завершение программы ===" << std::endl;
    return 0;
}