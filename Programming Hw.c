#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

void subject(int index);
void mention(float score);
bool checkScore(int score);
bool numOnly(char *score);

int main(){
    char score[20];
    int total = 0, points;
    for(int i = 0; i < 5; i++){
        subject(i);
        scanf("%s", score);
        if(!numOnly(score)) goto fail;
        points = atoi(score);
        if(!checkScore(points)) goto fail;
        mention((float)(points));
        total += points;
    }
    printf("\nTotal: %d\nAverage %.2f%%\n", total, (float)(total) / 5);
    mention((float)(total) / 5);
    exit(0);
    fail:
    printf("Input fail");
    return 0;
}

void subject(int index){
    char name[5][30];
    strcpy(name[0], "Computer Architecture: ");
    strcpy(name[1], "Programming Methodology: ");
    strcpy(name[2], "English for Computing: ");
    strcpy(name[3], "Graphic Design: ");
    strcpy(name[4], "Math for Computing: ");
    printf("%s", name[index]);
}

void mention(float score){
    float goal[] = {40, 45, 50, 65, 70, 80, 85, 100};
    char grade[] = "FEDCcBbA";
    int i;
    for(i = 0; i < 8; i++){
        if(score < goal[i]){
            break;
        }
    }
    printf("Mention: ");
    if(grade[i] == 'c'){
        printf("C+\n");
    }else if(grade[i] == 'b'){
        printf("B+\n");
    }else{
        printf("%c\n", grade[i]);
    }
}

bool checkScore(int score){
    return score > 100 ? false : true;
}

bool numOnly(char *score){
    char num[10] = "0123456789";
    int length, numLength, count = 0;
    length = strlen(score);
    numLength = strlen(num);
    for(int i = 0; i < length; i++){
        for(int j = 0; j < numLength; j++){
            if(*(score + i) == num[j]){
                count++;
            }
        }
    }
    return length - count ? false : true;
}