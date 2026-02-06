#include "MyString.h"
#include <iostream>

void demonstrateOperators() {
    std::cout << "\n=== Демонстрация работы операторов ===\n";
    
    // 1. Создание объектов
    std::cout << "\n1. Создание объектов:\n";
    MyString s1("Hello");
    MyString s2(" World");
    MyString s3;
    
    // 2. Демонстрация оператора []
    std::cout << "\n2. Демонстрация оператора []:\n";
    std::cout << "s1[0] = " << s1[0] << std::endl;
    s1[0] = 'h';  // Изменение символа
    std::cout << "После s1[0] = 'h': " << s1 << std::endl;
    
    const MyString cs("Constant");
    std::cout << "cs[0] = " << cs[0] << " (чтение из const объекта)" << std::endl;
    
    // 3. Демонстрация оператора +
    std::cout << "\n3. Демонстрация оператора +:\n";
    MyString s4 = s1 + s2;
    std::cout << "s1 + s2 = " << s4 << std::endl;
    
    // 4. Демонстрация оператора <<
    std::cout << "\n4. Демонстрация оператора <<:\n";
    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;
    
    // 5. Копирование и присваивание
    std::cout << "\n5. Копирование и присваивание:\n";
    MyString s5 = s1;  // Конструктор копирования
    std::cout << "s5 (копия s1): " << s5 << std::endl;
    
    MyString s6;
    s6 = s2;  // Оператор присваивания
    std::cout << "s6 (после s6 = s2): " << s6 << std::endl;
    
    // 6. Демонстрация метода length()
    std::cout << "\n6. Демонстрация метода length():\n";
    std::cout << "Длина s1: " << s1.length() << std::endl;
    std::cout << "Длина s2: " << s2.length() << std::endl;
    std::cout << "Длина s1 + s2: " << (s1 + s2).length() << std::endl;
    
    // 7. Self-assignment демонстрация
    std::cout << "\n7. Self-assignment:\n";
    s1 = s1;  // Должно корректно обработаться
    std::cout << "После s1 = s1: " << s1 << std::endl;
    
    std::cout << "\nОбъектов создано в этой функции: " << MyString::getObjectCount() << std::endl;
}

int main() {
    std::cout << "=== Начало программы ===\n";
    
    demonstrateOperators();
    
    std::cout << "\n=== Выход из main() ===\n";
    std::cout << "Объектов осталось в конце: " << MyString::getObjectCount() << std::endl;
    
    return 0;
}