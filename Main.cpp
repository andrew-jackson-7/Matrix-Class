//
//  Main.cpp
//  
//
//  Created by Andrew Jackson on 4/20/15.
//
//

#include "Matrix.h"

int main()
{
    //Matrix This_Matrix;
    //This_Matrix.print();
    
    //std::cout << "Please choose a value" << std::endl;
    
    double n;
    std::cin >> n;
    double m;
    std::cin >> m;
    
    Matrix Another_Matrix(n, m);
    /*int i;
    int j;
    
    std::cin >> i;
    std::cin >> j;
    
    std::cout << Another_Matrix.getVal(i,j);*/
    Another_Matrix.setFromFile("Reading_In.txt");
    
    Another_Matrix.print();
    
    Matrix To_Sum(n, m);
    To_Sum.setFromFile("Reading_In.txt");
    
    Matrix& matToBeSubtracted = To_Sum;
    
    Another_Matrix.matSub(matToBeSubtracted) -> print();
    
    Another_Matrix.matScalarMult(3.0) -> print();
    
    Another_Matrix.matMult(To_Sum) -> print();
    
}
