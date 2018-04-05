#include"Matrix.h"
#include<iostream>

//overloading operator = for matrices
void Matrix::operator = (const Matrix &b){
        this->rows = b.rows;
        this->columns = b.columns;
        for(int i = 0; i < this->rows; i++)
                for(int j = 0; j < this->columns; j++)
                        this->ele[i][j] = b.ele[i][j];
}

//overloading + operator for scalar and vector additions:
//vector
Matrix Matrix::operator + (const Matrix &b) const{
        Matrix result(this->rows, this->columns);
        if(this->rows != b.rows && this->columns != b.columns){
                std::cerr<<"Matrices not fit for addition!";
                return result;
        }
        for(int i =0; i < this->rows; i++)
                for(int j = 0; j < this->columns; j++)
                        result.ele[i][j] = this->ele[i][j] + b.ele[i][j];

        return result;
}
//scalar:
Matrix Matrix::operator + (const float a) const{
        Matrix result(this->rows, this->columns);
        for(int i =0; i < this->rows; i++)
                for(int j = 0; j < this->columns; j++)
                        result.ele[i][j] = this->ele[i][j] + a;

        return result;
}

//overloading operators - for scalar and vector substraction
//vector:
Matrix Matrix::operator - (const Matrix &b) const{
        Matrix result(this->rows, this->columns);
        if(this->rows != b.rows && this->columns != b.columns){
                std::cerr<<"Matrices not fit for substraction!";
                return result;
        }
        for(int i =0; i < this->rows; i++)
                for(int j = 0; j < this->columns; j++)
                        result.ele[i][j] = this->ele[i][j] - b.ele[i][j];

        return result;
}
//scalar:
Matrix Matrix::operator - (const float a) const{
        Matrix result(this->rows, this->columns);
        for(int i =0; i < this->rows; i++)
                for(int j = 0; j < this->columns; j++)
                        result.ele[i][j] = this->ele[i][j] - a;
        return result;
}

//overloading operator * for scalar and vector multiplication
//vector:
Matrix Matrix::operator * (const Matrix &b) const{
        Matrix result(this->rows, b.columns);
        float sum;
        if(this->columns != b.rows){
                std::cerr<<"Matrices not fit for multiplication!";
                return result;
        }
        for(int i = 0; i < this-> rows; i++){
                for(int j = 0; j < b.columns; j++){
                        sum = 0.0f;
                        for(int k = 0; k < this->columns; k++)                  //this needs 
                                sum += this->ele[i][j] * b.ele[i][j];           //improvement
                        result.ele[i][j] = sum;

                }
        }
        return result;
}

//scalar:
Matrix Matrix::operator * (const float a) const{
        Matrix result(this->rows, this->columns);
        for(int i =0; i < this->rows; i++)
                for(int j = 0; j < this->columns; j++)
                        result.ele[i][j] = this->ele[i][j] * a;

        return result;
}

//overloading operator / for scalar division
Matrix Matrix::operator / (const float a) const{
        Matrix result(this->rows, this->columns);
        for(int i =0; i < this->rows; i++)
                for(int j = 0; j < this->columns; j++)
                        result.ele[i][j] = this->ele[i][j] / a;
        return result;
}

//tranpose
Matrix Matrix::transpose() const{
        Matrix result(this->columns, this->rows);
        //some error checking here...
        for(int i = 0; i < result.rows; i++)
                for(int j = 0; j < result.columns; j++)
                        result.ele[i][j] = this->ele[j][i];
        result.print();
        return result;
}
