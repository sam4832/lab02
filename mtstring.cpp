#include "MyString.h"
#include <cstring>
#include <iostream>

// Инициализация статического счетчика
int MyString::objectCount = 0;

// Конструктор по умолчанию (Вариант 3: explicit)
MyString::MyString() {
    data = new char[1];
    data[0] = '\0';
    objectCount++;
    std::cout << "Default constructor created: \"" << data << "\" (Total objects: " << objectCount << ")" << std::endl;
}

// Конструктор из C-строки
MyString::MyString(const char* str) {
    copyString(str);
    objectCount++;
    std::cout << "Constructor from C-string created: \"" << data << "\" (Total objects: " << objectCount << ")" << std::endl;
}

// Конструктор копирования
MyString::MyString(const MyString& other) {
    copyString(other.data);
    objectCount++;
    std::cout << "Copy constructor created: \"" << data << "\" (Total objects: " << objectCount << ")" << std::endl;
}

// Деструктор (Вариант 5: с отладочным выводом)
MyString::~MyString() {
    std::cout << "Destroying MyString: \"" << data << "\" (Objects left: " << objectCount - 1 << ")" << std::endl;
    freeMemory();
    objectCount--;
}

// Оператор присваивания
MyString& MyString::operator=(const MyString& other) {
    std::cout << "Assignment operator: \"" << this->data << "\" = \"" << other.data << "\"" << std::endl;
    
    if (this != &other) {  // Использование this (требование 4)
        freeMemory();
        copyString(other.data);
    }
    return *this;  // Использование this (требование 4)
}

// Оператор [] для изменения (Вариант 4)
char& MyString::operator[](size_t index) {
    if (index >= length()) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

// Оператор [] для чтения (Вариант 4)
const char& MyString::operator[](size_t index) const {
    if (index >= length()) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

// Дружественная функция operator+ (Вариант 2)
MyString operator+(const MyString& lhs, const MyString& rhs) {
    size_t newLength = lhs.length() + rhs.length();
    char* newData = new char[newLength + 1];
    
    strcpy(newData, lhs.data);
    strcat(newData, rhs.data);
    
    MyString result(newData);
    delete[] newData;
    
    return result;
}

// Дружественная функция operator<<
std::ostream& operator<<(std::ostream& os, const MyString& str) {
    os << str.data;
    return os;
}

// Дружественная функция operator>>
std::istream& operator>>(std::istream& is, MyString& str) {
    const int BUFFER_SIZE = 256;
    char buffer[BUFFER_SIZE];
    
    if (is >> buffer) {
        str.freeMemory();
        str.copyString(buffer);
    }
    
    return is;
}

// Вспомогательные приватные методы
void MyString::copyString(const char* str) {
    if (str == nullptr) {
        data = new char[1];
        data[0] = '\0';
    } else {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }
}

void MyString::freeMemory() {
    delete[] data;
    data = nullptr;
}