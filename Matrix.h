//
//  Matrix.h
//  
//
//  Created by Andrew Jackson on 4/15/15.
//
//

#ifndef _Matrix_H
#define _Matrix_H

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <cstring>
#include <sstream>

//using std::stringstream;
//using std::istringstream;

class Matrix
{
    private:
    int n;
    int m;
    double val;
    double* UserMatrix;
    
    public:
    
    //function for building the matrix
    void Matrix_Maker(int n, int m);
    
    //default constructor
    Matrix();
    
    //Square Matrix Constructor
    Matrix(int n);
    
    //N x M Matrix Constructor
    Matrix(int n, int m);
    
    //get/set pairs
    int getRow();
    int setRow(int n);
    
    int getColumn();
    int setColumn(int m);
    
    double getVal(int n, int m);
    void setVal(int n, int m, double val);
    
    void setFromFile(std::string filename);
    
    //Addition
    Matrix* matAdd(Matrix& matToBeAdded);
    
    //Subtraction
    Matrix* matSub(Matrix& matToBeSubtracted);
    
    //Scalar Multiplication
    Matrix* matScalarMult(double scalar);
    
    //Matrix Multiplication
    Matrix* matMult(Matrix& matToBeMultiplied);
    
    //Print
    void print();
    
};

#endif
    
    
