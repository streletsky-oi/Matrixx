#pragma once
#include "vector.h"


template <class T>
class Matrix : public Vector<Vector<T>>
{
public:
    Matrix (size_t n) : Vector<Vector<T>>(n,0){
        for (size_t i = 0; i < n; i++){
            this->_array[i] = Vector<T> (n-i, i);
        }
    }
    Matrix(const Matrix& mt) : Vector<Vector<T>>(mt){

    }                    // копирование
    Matrix(const Vector<Vector<T> >& mt) : Vector<Vector<T>>(mt){

    } // преобразование типа
    Matrix& operator= (const Matrix& mt){
        this->_size = mt._size;
        this->_startIndex = mt._startIndex;
        for (size_t i = 0; i < this->_size; i++){
            delete [] this->_array[i];
            this->_array[i] = nullptr;
            this->_array[i] = mt._array[i];
        }

        return *this;
   }        // присваивание
    Matrix  operator+ (const Matrix& mt){
        return Vector<Vector<int>> :: operator+(mt);
    }        // сложение
    Matrix  operator- (const Matrix& mt){
        return Vector<Vector<int>> :: operator-(mt);
    }       // вычитание

    Matrix operator*(const Matrix& mt) {
    if (this->_size != mt._size) {
        throw std::invalid_argument("Matrices have incompatible sizes for multiplication.");
    }

    Matrix result(this->_size);

    for (size_t i = 0; i < this->_size; i++) { 
        for (size_t j = i; j < this->_size; j++) { 
            T sum = 0;

            for (size_t k = i; k <= j; k++) {
                if ((k - i) < this->_array[i].GetSize() && (j - k) < mt._array[k].GetSize()) {
                    sum += this->_array[i][k - i] * mt._array[k][j - k];
                }
            }

            result._array[i][j - i] = sum; 
        }
    }

    return result;
}

    // ввод / вывод
    friend istream& operator>>(istream& in, Matrix& mt)
    {
        for (int i = 0; i < mt._size; i++)
            in >> mt._array[i];
        return in;
    }
    friend ostream& operator<<(ostream& os, const Matrix& mt)
    {

        for (int i = 0; i < mt._size; i++){
        os << "|";
        for (size_t j = 0; j < i; j++) os << "0, ";
        os << mt._array[i] << "|" << endl;}
        return os;
    }
};
