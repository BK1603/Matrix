#include<iostream>
#include"Matrix.h"

//ctor
Matrix::Matrix(int i, int j){
        rows = i;
        columns = j;
        ele = new float*[rows];
        for(int n = 0; n < rows; n++){
                ele[n] = new float[columns];
                for(int m = 0; m < columns; m++)
                        ele[n][m] = NULL;
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

//tranpose
//wanted a static implementation, but well
//segmentation fault :'(
Matrix Matrix::transpose() const{
        Matrix result(this->columns, this->rows);
        //some error checking here...
        for(int i = 0; i < result.rows; i++)
                for(int j = 0; i < result.columns; j++)
                        result.ele[i][j] = this->ele[j][i];
        return result;
}

