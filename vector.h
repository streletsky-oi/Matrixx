#pragma once
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

template<class T>
class Vector
{
protected:
    T* _array;
    size_t _size;
    size_t _startIndex;
public:
    Vector() : _size(10), _startIndex(0){ //баз конструктора
        _array = new T[_size];
        for (int i = 0; i < _size; i++){
            _array[i] = 0;
        }
    }

    Vector(size_t size, size_t startIndex){ //конструктор баз с размером и индексом
        _array = new T[size];
        _size = size;
        _startIndex = startIndex;
        for (int i = 0; i < _size; i++){
            _array[i] = 0;
        }
    };
    
    Vector(size_t size) : _size(size), _startIndex(0){ //баз конструктор с ращмепром
        _array = new T[_size];
        for (int i = 0; i < _size; i++){
            _array[i] = 0;
        }
    }

    Vector(size_t size, size_t startIndex, T* array) : _size(size), _array(new T[size]), _startIndex(startIndex){ //конструктор с массивом плюс размером и индексом старта
        for (int i = 0; i < _size; i++){
            _array[i] = array[i];
        }
    }

    Vector(const Vector<T>& vec) : _size(vec._size), _array(new T[vec._size]){ //копирования?
        for (int i = 0; i < _size; i++){
            _array[i] = vec._array[i];
        }
    }

    Vector(Vector<T>&& vec) noexcept : _array(vec._array), _size(vec._size), _startIndex(vec._startIndex) {
        cout << "ABOBA";
        vec._array = nullptr;
        vec._size = 0;
        vec._startIndex = 0;
}

    size_t GetSize() const{ //размер
       return _size; 
    };

    ~Vector(){ //деструктор
        delete [] _array;
        _array = nullptr;
    }

    T& GetElem(size_t i){ //метод функция получит элемент под индексом
        if (i >= _size){
            throw "Out of range";
        }
        return _array[i];
    };

    size_t GetStartIndex() const{ // получаем старт индекс
        return _startIndex;
    };

    Vector operator+(const T& tmp) const{ // перегрузили сложение
        Vector ans(*this);
        for (size_t i = 0; i < _size; i++)
            ans[i] += tmp;
        return ans;
    };
    Vector operator-(const T& tmp) const{ // перегрузили вычитание
        Vector ans(*this);
        for (size_t i = 0; i < _size; i++)
            ans[i] -= tmp;
        return ans;
    };

    Vector operator*(const T& tmp) const{ // перегрузили умножение
        Vector ans(*this);
        for (size_t i = 0; i < _size; i++)
            ans[i] *= tmp;
        return ans;
    };


    Vector& operator=(const Vector<T>& vec){ // присваивание
        _size = vec._size;
        _startIndex = vec._startIndex;
        delete [] _array;
        _array = nullptr; ?
        _array = new T[_size];
        for (int i = 0; i < _size; i++){
            _array[i] = vec._array[i];
        }
        return *this;
    }

    T& operator[](int index){ 
        return _array[index];
    }

    friend istream& operator>>(istream& in, Vector& vec) 
    {
        for (int i = 0; i < vec._size; i++)
            in >> vec._array[i];
        return in;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector& tmp){
        for (int i = 0; i < tmp._size; i++){
            os << tmp._array[i];
            if (i + 1 != tmp._size) os << ", ";
        }
        return os;
    }


   
};
