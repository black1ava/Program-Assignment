#include<stdio.h>

#define SIZE 7

int larger(int a, int b);
int maximum(int *arr);
int *arrangement(int *arr);
int *reverse(int *arr);

int main(){

    int *nums;
    
    nums = (int*)calloc(SIZE, sizeof(int));
    
    for(int i = 0; i < SIZE; i++){
        printf("Number %d: ", i + 1);
        scanf("%d", &*(nums + i));
    }
    
    int *deNum = arrangement(nums);
    int *asNum = reverse(deNum);
    
    printf("\nDescent: ");
    
    for(int i = 0; i < SIZE; i++){
        printf("%d ", *(deNum + i));
    }
    
    printf("\nAscent : ");
    
    for(int i = 0; i < SIZE; i++){
        printf("%d ", *(asNum + i));
    }
    
    free(nums);
    
    return 0;
}

int larger(int a, int b){
    return a > b ? a : b;
}

int maximum(int *arr){
    int max = 0;
    
    for(int i = 0; i < SIZE; i++){
       max = larger(max, *(arr + i));
    }
    
    return max;
}

int *arrangement(int *arr){
    int *newArr;
    
    int size = SIZE;
    
    newArr = (int*)calloc(SIZE, sizeof(int));
    
    for(int i = 0; i < SIZE; i++){
        
        *(newArr + i) = maximum(arr);
        for(int j = 0; j < size; j++){
            if(*(arr + j) == *(newArr + i)){
                if(j < size){
                    for(int k = j; k <= size - 1; k++){
                        *(arr + k) = *(arr + k + 1);
                    }
                    break;
                }
            }
        }
        
        size--;
    }
    return newArr;
}

int *reverse(int *arr){
    int *newArr = (int*)calloc(SIZE, sizeof(int));
    
    for(int i = 0, j = SIZE - 1; i < SIZE, j >= 0; i++, j--){
        *(newArr + i) = *(arr + j);
    }
    return newArr;
}