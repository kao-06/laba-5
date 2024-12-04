#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void int_in(int* n){
    char c[100];
    int error = 0;
    do{
    error = 0;
    fgets(c, sizeof(c), stdin);

    if (c[0] < '0' || c[0] > '9') {
      if (c[0] != '-') {
        error = 1;
      }
    }

    for (int i = 1; c[i] != '\n'; i++)
    {
      if (c[i] < '0' || c[i] > '9') {
        error = 1;
        break;
      }
    }

    if(!error)
    {
      if (sscanf(c, "%d", n) == 1)
        {
          return;
        }
      else{printf("Please enter one number\n");}
    }
    else{printf("Please enter a number\n");}
    }while(error);
    return;
}
int rand_in(){
    int  n = 0; 
    srand(clock());
    n = rand() % 129 - 35;
    return n;
}
void shift(int** a, int n){
    int* temp = (int*)malloc(n * sizeof(int));
    for(int j = 0;j < n;j++){
        temp[0] = a[n - 1][j];
        for(int i = 0;i < n - 1; i++){
            temp[i + 1] = a[i][j];
        }
        for(int l = 0;l < n;l++)
            a[l][j] = temp[l];
    }
    free(temp);
}
int main(){
    int n, f;
    int** a;
    system("clear");
    f = -1;
    while(f != 1 && f != 0){
        puts("for random input enter - '1', for manual - '0'");
        int_in(&f);
    }
    if(f == 1){
        n = -1;
        while(n <= 0)
            n = rand_in();
        printf("%d", n);
        puts("\n");
        a = (int**)malloc(n * sizeof(int*));
        for(int i = 0;i < n;i++)
            a[i] = (int*)malloc(n * sizeof(int));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                a[i][j] = rand_in();
                printf("%d " "", a[i][j]);
            }
            puts("\n");
        }
    }
    else{
        puts("Please enter size of sqare matrix(n*n):");
        int_in(&n);
        a = (int**)malloc(n * sizeof(int*));
        for(int i = 0;i < n;i++)
            a[i] = (int*)malloc(n * sizeof(int));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                int_in(&a[i][j]);
            }
        } 
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                printf("%d " "", a[i][j]);
            }
            puts("\n");
        }
    }
    puts("-------------------------------------");
    shift(a, n);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            printf("%d " "", a[i][j]);
        }
        puts("\n");
    }
return 0;}