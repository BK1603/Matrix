#include<iostream>
#include"Matrix.h"
#include<limits>

//ctor
Matrix::Matrix(int i, int j){
        rows = i;
        columns = j;
        ele = new float*[rows];
        for(int n = 0; n < rows; n++){
                ele[n] = new float[columns];
                for(int m = 0; m < columns; m++)
                        ele[n][m] = std::numeric_limits<float>::quiet_NaN();		//to initialise the Matrix with nan
        }
}

//to display the matrix
void Matrix::print(){
        for(int i = 0; i < rows; i++){
                for(int j = 0; j < columns; j++)
                        std::cout<<ele[i][j]<<" ";
                std::cout<<"\n";
        }
}
