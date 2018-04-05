#include<iostream>
#include"Matrix.h"

int main(){
	Matrix a(3, 3);
	Matrix b(3, 3);
	Matrix c(3, 3);

	for(int i = 0; i < a.rows; i++){
		for(int j = 0; j < a.columns; j++){
			a.ele[i][j]=i;
			b.ele[i][j]=j;
		}
	}

	c = a+b;
	a.print();
	std::cout<<std::endl;
	c.print();

	return 0;

}
