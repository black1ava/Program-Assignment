#include<stdio.h>
#include<conio.h>
#include<math.h>

void line();//show end line

int Range(int num);//how big is a number

void space(int n);//space from each number

//display matrix
void showMatrix(int a, int b, int matrix[][b]);

int main(){

    int m, n, p, q;
    
    //get row and column for each matrix
    printf("Row and and Column of A: ");
    scanf("%d%d", &m, &n);
    printf("Row and and Column of B: ");
    scanf("%d%d", &p, &q);
    
    //Make sure those rows and columns are matched
    if(!(m - p) && !(n - q)){
        printf("Matrix can be added\nMatrix A: \n");
        
        //insert number to each matrix
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
        
        //finish inserting :)
        clrscr();
        
        //display matrix to the screen
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


//line function is is used to display
//__________
void line(){
    for(int i = 0; i < 20; i++){
        printf("_");
    }
    printf("\n");
}

//Range function is used to determined
//range of number whether it is in 
//10 class and 100 class...
//or negative number
int Range(int num){
    int numberRange[5];
    
    //insert number
    //from 10 - 100000
    for(int i = 0; i < 5; i++){
        numberRange[i] = pow(10, i + 1);
    }
    int i;
    for(i = 0; i < 5; i++){
        if(num < numberRange[i]){
            break;
        }
    }
    
    //return the index 
    //so, we can use index to determin
    //the position of the number
    //thus, all numbers are in the 
    //same line
    return i;
}


//space function is used to add space
//from each number
//n is, technically, the value return from
//function Range
void space(int n){
    
    //"dis", make sure the number is lower
    //than 100,000 or the program will crash
    int dis = 6 - n;
    for(int i = 0; i < dis; i++){
        printf(" ");
    }
}

//This function is the function that
//gather all the functions together
void showMatrix(int a, int b, int matrix[][b]){
    int range;
    
    //display the matrix :p
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            if(matrix[i][j] >= 0){
                range = Range(matrix[i][j]);
                space(range);
                printf("%d", matrix[i][j]);
            }else{
                int clone = -matrix[i][j];
                range = Range(clone);
                
//if number is negative, make sure
//the space is shorter respectively to its range
//or the number won't be in the same line
                range++;
                space(range);
                printf("%d", matrix[i][j]);
            }
        }
        printf("\n");
    }
    line();
}