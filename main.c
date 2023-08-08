
#include <stdio.h>
#include <stdlib.h>

void in(int(*mtrx)[6], int nrow, int ncol,int value)
{
    for(int i=0; i<ncol; i++)
        for (int j=0; j<nrow; j++)
            mtrx[i][j]=value;
}
//Заполняем
void out(int(*mtrx)[6], int nrow, int ncol, char a)
{
    printf("%c\n",a);
    for(int i=0; i<ncol; i++)
    {
        for (int j=0; j<nrow; j++)
        {
            printf("%d ",mtrx[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}
//Выводим
void change_p(int *p, int(*mtrx_1)[6], int(*mtrx_2)[6], int(*mtrx_3)[6])
{
    if(comparison (mtrx_1, mtrx_2)&&comparison (mtrx_2, mtrx_3))
    {
        *p = 2;
    }
    else if(comparison (mtrx_1, mtrx_2)||comparison (mtrx_2, mtrx_3)||comparison (mtrx_1, mtrx_3))
    {
        *p =1;
    }
    else *p=0;
}//Меняем р
int comparison( int(*mtrx_1)[6], int(*mtrx_2)[6] )
{
    for(int i=0; i<6; i++)
    {
        for (int j=0; j<6; j++)
        {
            if(mtrx_1[i][j]!=mtrx_2[i][j])
            {
                return 0;
            }
        }
    }

    return 1;
}//Сравниваем
void main()
{
    int A[6][6],B[6][6],C[6][6];
    int a = 3;
    int *p = &a;
    int rows=sizeof(A)/sizeof(A[0]);
    int cols=sizeof(A[0])/sizeof(A[0][0]);
    in(A, rows, cols, 1);
    in(B, rows, cols, 2);
    in(C, rows, cols, 3);

    out(A, rows, cols, 'A');
    out(B, rows, cols, 'B');
    out(C, rows, cols, 'C');
    change_p(p, A, B, C);
    printf("%d",*p);
}
