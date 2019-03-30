//
//  Matrix.cpp
//  
//
//  Created by Andrew Jackson on 4/15/15.
//
//

#include "Matrix.h"

//Making the Matrix
void Matrix::Matrix_Maker(int n, int m)
{
    int i, j;
    this -> UserMatrix = new double[n * m];
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            this -> UserMatrix[(i - 1) * m + (j - 1)] = 0;
        }
    }
}

/*int getRow();
{
    return this -> n;
}

int getColumn()
{
    return this -> m;
}*/

//default Constructor
Matrix::Matrix()
{
    int check = 0;
    int n, m;
    
    std::cout << "Please select the row number." << std::endl;
    std::cin >> n;
    
    std::cout << "Please select the column number." << std::endl;
    std::cin >> m;
    
    while (/*(n < 1 && typeid(n).name() != "int") && (m < 1 && typeid(m).name() != "int")*/ check == 0)
    {
        if ((n >= 1 && m >= 1) && (strncmp(typeid(n).name(), "i", 1) == 0) && (strncmp(typeid(m).name(), "i", 1) == 0))
        {
            this -> n = n;
            this -> m = m;
            this -> Matrix_Maker(this -> n, this -> m);
            check = 1;
        }
        else if (strncmp(typeid(n).name(), "NSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE", 4) == 0)
        {
            std::cout << "You entered a string you buffoon!" << std::endl;
            
            check = 0;
        }
        else
        {
            std::cout << "You did not enter valid dimensions for your matrix." << std::endl;
            std::cout << "Please try again below." << std::endl;
            
            std::cout << "Please enter a value for n." << std::endl;
            std::cin >> n;
            
            std::cout << "Please enter a value for m." << std::endl;
            std::cin >> m;
            
            check = 0;
        }
    }
}
//making a square matrix
Matrix::Matrix(int n)
{
    int check = 0;
    
    while (/*n < 1 && typeid(n).name() != "int"*/ check == 0)
    {
        if (n >= 1 && (strncmp(typeid(n).name(), "i", 1) == 0))
        {
            this -> n = n;
            this -> m = n;
        
            this -> Matrix_Maker(this -> n, this -> m);
            
            check = 1;
        }
        else
        {
            std::cout << "You did not enter a valid dimension for your matrix." << std::endl;
            std::cout << "Please try again below." << std::endl;
            
            std::cout << "Please enter a value for n." << std::endl;
            std::cin >> n;
            
            check = 0;
        }
    }
}

//Making an n x m matrix
Matrix::Matrix(int n, int m)
{
    if ((n >= 1 && m >= 1) && (strncmp(typeid(n).name(), "i", 1) == 0) && (strncmp(typeid(m).name(), "i", 1) == 0))
    {
        this -> n = n;
        this -> m = m;
    
        this -> Matrix_Maker(this -> n, this -> m);
    }
    else
    {
        std::cout << "Sorry these are not valid entries for a matrix." << std::endl;
    }
}

//get the value in the matrix corresponding to the nth row and the jth column
double Matrix::getVal(int n, int m)
{
    return this -> UserMatrix[(n - 1) * (this -> m) + (m - 1)];
}

//set the value of the element in the nth row and the mth column
void Matrix::setVal(int n, int m, double val)
{
    this -> UserMatrix[(n - 1) * (this -> m) + (m - 1)] = val;
}

void Matrix::setFromFile(std::string filename)
{
    std::ifstream dataIn;
    dataIn.open(filename);
    std::string store;
    std::istringstream char_element;
    int count = 0;
    int newcount = 0;
    
    while (getline(dataIn, store))
    {
        char_element.str(store);
        while (char_element >> store)
        {
            count++;
            //std::cout << count << std::endl;
        }
        char_element.clear();
        char_element.seekg(0,char_element.beg);
    }
    
    //std::cout << count << std::endl;
    double* String_Vals = new double[count];
    dataIn.clear();
    dataIn.seekg(0,dataIn.beg);
    
    char_element.clear();
    char_element.seekg(0,char_element.beg);
    
    double Result;
    int row_count = 0;
    double Value;
    
    while (getline(dataIn, store))
    {
        std::cout << row_count << std::endl;
        char_element.str(store);
        while (char_element >> store)
        {
            std::stringstream convert(store);
            convert >> Result;
            //store = Result;
            String_Vals[newcount] = Result;
            newcount++;
        }
        char_element.clear();
        char_element.seekg(0,char_element.beg);
        
        row_count++;
    }
    
    std::cout << row_count << std::endl;
    int column_count = count/row_count;
    
    this -> Matrix_Maker(row_count, column_count);
    this -> m = column_count;
    this -> n = row_count;
    
    for (int i = 1; i <= row_count; i++)
    {
        for (int j = 1; j <= column_count; j++)
        {
            this -> UserMatrix[(i - 1) * column_count + (j - 1)] = String_Vals[(i - 1) * column_count + (j - 1)];
        }
    }
}

Matrix* Matrix::matAdd(Matrix& matToBeAdded)
{
    //int n, m;
    //int row_count;
    //int column_count;
    
    //n = matToBeAdded.getRow();
    //m = matToBeAdded.getColumn();
    
    if (this -> n == n && this -> m == m)
    {
    
        Matrix* My_Add_Matrix = new Matrix(this -> n, this -> m);
    
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                My_Add_Matrix -> setVal(i, j, (this -> getVal(i,j) + getVal(i,j)));
            }
        }
        
        return My_Add_Matrix;
    }
    else
    {
        std::cout << "The dimensions of the matrices you are trying to add do not match." << std::endl;
        
        return NULL;
    }
}

Matrix* Matrix::matSub(Matrix& matToBeSubtracted)
{
    if (this -> n == n && this -> m == m)
    {
        Matrix* My_Sub_Matrix  = new Matrix(this -> n, this -> m);
        
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                My_Sub_Matrix -> setVal(i, j, (this -> getVal(i,j) - getVal(i,j)));
            }
        }
        
        return My_Sub_Matrix;
    }
    else
    {
        std::cout << "The dimensions of the matrices you are trying to add do not match." << std::endl;
        
        return NULL;
    }
}

Matrix* Matrix::matScalarMult(double scalar)
{
    Matrix* My_Scal_Matrix = new Matrix(this -> n, this -> m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            My_Scal_Matrix -> setVal(i, j, (scalar * this -> getVal(i, j)));
        }
    }
    
    return My_Scal_Matrix;
}

Matrix* Matrix::matMult(Matrix& matToBeMultiplied)
{
    if (this -> m == n)
    {
        int this_count = 0;
        double Matrix_Elements[(this -> n) * m * n];
        Matrix* My_Multi_Matrix = new Matrix((this -> n), m);
    
        for (int a = 1; a <= n; a++)
        {
        for (int b = 1; b <= this -> m; b++)
        {
        for (int d = 1; d <= this -> n; d++)
        {
            for (int c = 1; c <= m; c++)
                {
                    Matrix_Elements[((d - 1) * m + (c - 1)) + a * ((this -> n) * m)] = (this -> getVal(d,b)) * getVal(a,c);
                    //std::cout << Matrix_Elements[((d - 1) * m + (c - 1)) + a * ((this -> n) * m)] << std::endl;
                    //std::cout << (sizeof(Matrix_Elements)/sizeof(*Matrix_Elements)) << std::endl;
                    this_count++;
                }
            }
        }
        }
        std::cout << (sizeof(Matrix_Elements)/sizeof(*Matrix_Elements)) << std::endl;
        std::cout << this_count << std::endl;
        double Sum = 0;
        //(sizeof(Matrix_Elements)/sizeof(*Matrix_Elements))/
        int i;
        int j;
        for (int k = 1; k <= n; k++)
        {
        for (i = 1; i <= this -> n; i++)
        {
            for (j = 1; j <= m; j++)
            {
                //for (int k = 1; k <= n; k++)
                //{
                    Sum = Sum + Matrix_Elements[((i - 1) * m + (j - 1)) + (k - 1) * ((this -> n) * m)];
                //}
                
                //My_Multi_Matrix -> setVal(i, j, Sum);
            }
        }
        My_Multi_Matrix -> setVal(i, j, Sum);
        }
        return My_Multi_Matrix;
    }
    else
    {
        std::cout << "The dimensions of the matrices do not satisfy the criteria for matrix multiplication." << std::endl;
        
        return NULL;
    }
}

void Matrix::print()
{
    for (int i = 1; i <= this -> n; i++)
    {
        for (int j = 1; j <= this -> m; j++)
        {
            std::cout << this -> UserMatrix[(i - 1) * (this -> m) + (j - 1)] << " ";
        }
        
    std::cout << std::endl;
    
    }
}
    
        /*for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n, i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    My_Mutli_Matrix.setVal(i, j, (Matrix_Elements[(i - 1) * m + (j - 1)] + Matrix_Elements[((this -> n) * m * k) * ((i - 1) * m + (j - 1))] + Matrix_Elements[))*/
