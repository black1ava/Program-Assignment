#include<stdio.h>

int main(){
    int n;
    printf("Input line: ");
    scanf("%d", &n);
    for(int i = n; i >= 0; i--){
        for(int j = i; j < n; j++){
            printf("X ");
        }
        printf("\n");
    }
    printf("\n");
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            printf("$ ");
        }
        printf("\n");
    }
    printf("\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            printf("  ");
        }
        for(int k = n; k > i; k--){
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}