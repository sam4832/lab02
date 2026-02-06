#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

class MyString {
private:
    char* data;
    static int objectCount;  // Статический счетчик объектов
    
public:
    // Конструкторы
    explicit MyString();  // Вариант 3: explicit конструктор по умолчанию
    explicit MyString(const char* str);  // explicit конструктор из const char*
    
    // Правило трех
    ~MyString();  // Деструктор (Вариант 5: с отладочным выводом)
    MyString(const MyString& other);  // Конструктор копирования
    MyString& operator=(const MyString& other);  // Оператор присваивания
    
    // Методы доступа
    const char* c_str() const { return data; }
    int length() const { return strlen(data); }  // Вариант 1: метод length()
    
    // Перегрузка операторов
    char& operator[](size_t index);  // Для изменения символа (Вариант 4)
    const char& operator[](size_t index) const;  // Для чтения (Вариант 4)
    
    // Дружественные функции (Вариант 2)
    friend MyString operator+(const MyString& lhs, const MyString& rhs);
    friend std::ostream& operator<<(std::ostream& os, const MyString& str);
    friend std::istream& operator>>(std::istream& is, MyString& str);
    
    // Статический метод для получения счетчика объектов
    static int getObjectCount() { return objectCount; }
    
private:
    // Вспомогательная функция для копирования строки
    void copyString(const char* str);
    // Вспомогательная функция для освобождения памяти
    void freeMemory();
};

#endif // MYSTRING_H