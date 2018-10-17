#include <iostream>
#include <string>
#include "matrix.cpp"
//651
using namespace std;

int main()
{
    int button;
    while (true)
    {
        cout << " [1] - Add matrix\n"
                " [2] - Sub matrix\n"
                " [3] - Mul matrix\n"
                " [4] - Sum of matrix elements row and col\n"
                " [0] - Exit\n";
        cin >> button;
        system("cls");
        switch (button)
        {
            case 1://add
            {
                cout<<"FLOAT"<<endl;
                matrix<float> M1;
                M1.input_mat();
                matrix<float> M2;
                M2.input_mat();
                M1.output_mat();
                M2.output_mat();
                matrix<float> M_Res = M1 + M2;
                M_Res.output_mat();
            }
            break;
            case 2://sub
            {
                cout<<"LONG"<<endl;
                matrix<long> M1;
                M1.input_mat();
                matrix<long> M2;
                M2.input_mat();
                M1.output_mat();
                M2.output_mat();
                matrix<long> M_Res = M1 - M2;
                M_Res.output_mat();
            }
            break;
            case 3://mul
            {
                cout<<"INT"<<endl;
                matrix<int> M1;
                M1.input_mat();
                matrix<int> M2;
                M2.input_mat();
                M1.output_mat();
                M2.output_mat();
                matrix<int> M_Res = M1 * M2;
                M_Res.output_mat();
            }
            break;
            case 4://sum_col_and_row
            {
                cout<<"FLOAT"<<endl;
                matrix<float> M1;
                M1.input_mat();
                M1.output_mat();
                M1.sum_row_mat();
                M1.sum_col_mat();
                M1.output_sum_col_and_row();
            }
            break;
            case 0://exit
            {
                system("pause");
            }
            return 0;
            default:
                printf("Такой кнопки нет(\n");
                break;
        }
    }
}
