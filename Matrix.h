#ifndef MATRIX_H
#define MATRIX_H

#include<iostream>

class Matrix{
public:
	int rows;
	int columns;
	float **ele;

	Matrix(int i, int j);
	
	void print();

	//oaverloaded operators:
	//scalar operations
	Matrix operator + (const float a) const;
	Matrix operator - (const float a) const;
	Matrix operator * (const float a) const;
	Matrix operator / (const float a) const;

	//matrix specific operations
	Matrix operator + (const Matrix &b) const;
        Matrix operator - (const Matrix &b) const;
	Matrix operator * (const Matrix &b) const;

	//copy ctor
	void operator = (const Matrix &b);

	//utility functions:
	//transpose a matrix
	Matrix transpose() const;
	//function to map a algebric function to all elements, takes a function and matrix as arguements, returns matrix

        ~Matrix(){
                for(int i = 0; i < rows; i++)
                        delete [] ele[i];
                delete [] ele;
        }


};

#endif
