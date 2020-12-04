#include<stdio.h>
#include<conio.h>
#include<math.h>

void line();
int Range(int num);
void space(int n);
void showMatrix(int a, int b, int matrix[][b]);

int main(){
    int m, n, p, q;
    printf("Row and and Column of A: ");
    scanf("%d%d", &m, &n);
    printf("Row and and Column of B: ");
    scanf("%d%d", &p, &q);
    if(!(m - p) && !(n - q)){
        printf("Matrix can be added\nMatrix A: \n");
        int matrixA[m][n], matrixB[p][q], matrixC[m][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                scanf("%d", &matrixA[i][j]);
            }
        }
        clrscr();
        printf("Matrix B: \n");
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                scanf("%d", &matrixB[i][j]);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
            }
        } 
        clrscr();
        printf("(Row, Column) = (%d, %d)\n", m , n);
        line();
        printf("Matrix A: \n");
        showMatrix(m, n, matrixA);
        printf("Matrix B: \n");
        showMatrix(m, n, matrixB);
        printf("Matrix C = Matrix A + Matrix B: \n");
        showMatrix(m, n, matrixC);
    }else{
        printf("Matrix cannot be added");
    }
    return 0;
}

void line(){
    for(int i = 0; i < 20; i++){
        printf("_");
    }
    printf("\n");
}

int Range(int num){
    int numberRange[5];
    for(int i = 0; i < 5; i++){
        numberRange[i] = pow(10, i + 1);
    }
    int i;
    for(i = 0; i < 5; i++){
        if(num < numberRange[i]){
            break;
        }
    }
    return i;
}

void space(int n){
    int dis = 6 - n;
    for(int i = 0; i < dis; i++){
        printf(" ");
    }
}

void showMatrix(int a, int b, int matrix[][b]){
    int range;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            if(matrix[i][j] >= 0){
                range = Range(matrix[i][j]);
                space(range);
                printf("%d", matrix[i][j]);
            }else{
                int clone = -matrix[i][j];
                range = Range(clone);
                range++;
                space(range);
                printf("%d", matrix[i][j]);
            }
        }
        printf("\n");
    }
    line();
}