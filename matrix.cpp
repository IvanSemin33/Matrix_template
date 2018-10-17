#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string.h>

using namespace std;

template <typename Type>
class matrix
{
    Type *sum_col;
    Type *sum_row;
    int x, y;
    Type **mat;
    bool status_sum=false;
    string name;
public:
    matrix();
    matrix(int X,int Y,string mat_name);
    matrix(const matrix<Type> &Matrix);
    ~matrix();
    void dynamic_mat();
    void delete_dynamic_mat();
    void input_mat();
    void output_mat()const;
    matrix<Type> operator+(matrix<Type> Matrix)const;
    matrix<Type> operator-(matrix<Type> Matrix)const;
    matrix<Type> operator*(matrix<Type> Matrix)const;
    void sum_row_mat();
    void sum_col_mat();
    void output_sum_col_and_row()const;
};


template <typename Type>
matrix<Type>::matrix() : x(0),y(0) {}

template <typename Type>
matrix<Type>::matrix(int X,int Y,string mat_name) : x(X), y(Y), name(mat_name)//data
{
    dynamic_mat();
}

template <typename Type>
matrix<Type>::matrix(const matrix<Type> &Matrix)//copy
{
      x=Matrix.x;
      y=Matrix.y;
      dynamic_mat();
      mat = Matrix.mat;
      name = Matrix.name + "(Copy)";
}

template <typename Type>
matrix<Type>::~matrix()
{
    delete_dynamic_mat();
    if (status_sum)
    {
        delete[] sum_col;
        delete[] sum_row;
    }
}

template <typename Type>
void matrix<Type>::dynamic_mat()
{
    mat = new Type *[y];
    for (int i = 0; i < y; i++)
    {
        mat[i] = new Type[x];
    }
}

template <typename Type>
void matrix<Type>::input_mat()
{
    cout << "Enter Name of the matrix " << name << "  : ";
    cin >> name;
    cout << "Enter the number of col of the matrix " << name << "  : ";
    cin >> x;
    cout << "Enter the number of rows of the matrix " << name << " : ";
    cin >> y;
    dynamic_mat();
    cout << "Enter the elements of the matrix "<<name<<" : " << endl;
    for (int i = 0; i < y; i++)
        for (int j = 0; j < x; j++)
            cin >> mat[i][j];
}

template <typename Type>
void matrix<Type>::output_mat()const
{
    cout << name <<" : " << endl;
    cout << setw(5);
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            cout << mat[i][j] << setw(10);
        }
        cout << endl;
    }
}

template <typename Type>
matrix<Type> matrix<Type>::operator+(matrix<Type> Matrix)const
{
    string mat_name = "Matrix-Result";
    matrix<Type> result (x,y,mat_name);
    for (int i = 0; i < y; i++)
        for (int j = 0; j < x; j++)
        {
            result.mat[i][j] = mat[i][j] + Matrix.mat[i][j];
        }
    return result;
}

template <typename Type>
matrix<Type> matrix<Type>::operator-(matrix<Type> Matrix)const
{
    char mat_name[] = { "Matrix-Result" };
    matrix<Type> result (x,y,mat_name);
    for (int i = 0; i < y; i++)
        for (int j = 0; j < x; j++)
        {
            result.mat[i][j] = mat[i][j] - Matrix.mat[i][j];
        }
    return result;
}

template <typename Type>
matrix<Type> matrix<Type>::operator*(matrix<Type> Matrix)const
{
    char mat_name[] = { "Matrix-Result" };
    int X=x;
    if (x>y) X=y;
    matrix<Type> result (X,X,mat_name);
    for(int i=0; i< y; i++)
        for(int j=0; j< y; j++)
        {
            result.mat[i][j] = 0;
            for (int v = 0; v < x; v++)
               result.mat[i][j] += mat[i][v] * Matrix.mat[v][j];
        }
    return result;
}

template <typename Type>
void matrix<Type>::sum_row_mat()
{
    sum_row = new Type[y];
    for (int k = 0; k < y; ++k) sum_row[k]=0;
    for (int i = 0; i < y; i++)
        for (int j = 0; j < x; j++)
            sum_row[i] += mat[i][j];

    status_sum=true;
}

template <typename Type>
void matrix<Type>::sum_col_mat()
{
    sum_col = new Type[x];
    for (int k = 0; k < x; ++k) sum_col[k]=0;

    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            sum_col[i] += mat[j][i];
}
template <typename Type>
void matrix<Type>::output_sum_col_and_row()const
{
    cout << "The sum of elements of each row of the matrix " << name << " :" << endl;
    cout<<setw(5);
    for (int i = 0; i < y; i++)
    {
        cout << " [" << i+1 << "]   ";
        cout << sum_row[i] << setw(5) << endl;
    }

    cout << "The sum of elements of each col of the matrix " << name << " :" << endl;
    cout<<setw(5);
    for (int i = 0; i < x; i++)
    {
        cout << " [" << i << "]   ";
        cout << sum_col[i] << setw(5) << endl;
    }
}

template <typename Type>
void matrix<Type>::delete_dynamic_mat()
{
    for (int i = y - 1; 0 <= i; i--)
        delete[] mat[i];
}
