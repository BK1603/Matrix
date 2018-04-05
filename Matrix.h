#ifndef MATRIX_H
#define MATRIX_H

#include<iostream>

class Matrix{
public:
	int rows;
	int columns;
	float **ele;

	Matrix(int i, int j);

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

	//Mathematical functions:
	//transpose
	Matrix transpose() const;

	//map a function to all values
	Matrix map(float (*functionToMap)(float x)) const;

	//utility functions:
	void print();
	//function to map a algebric function to all elements, takes a function and matrix as arguements, returns matrix

        ~Matrix(){
                for(int i = 0; i < rows; i++)
                        delete [] ele[i];
                delete [] ele;
        }


};

#endif
