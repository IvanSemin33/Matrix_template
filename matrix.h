/*#ifndef LAB2_MATRIX_H
#define LAB2_MATRIX_H
#include <string>

template <typename Type>
class matrix
{
        Type *sum_col;
        Type *sum_row;
        int x, y;
        Type **mat;
        bool status_sum=false;
        std::string name;
    public:
        matrix();
        matrix(int X,int Y,std::string mat_name);
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

#endif //LAB2_MATRIX_H*/
