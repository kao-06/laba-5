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
void delete(int *a, int i, int n){
    int* temp = (int*)malloc((n - 1) * sizeof(int));
    int j = 0;
    for(int l = 0;l < n;l++){
        if(l != i){
            temp[j] = a[l];
            j++; 
        }
    }
    a = realloc(a, (n - 1) * sizeof(int));
    for(int l = 0;l < n - 1;l++)
        a[l] = temp[l];
    free(temp);
}
int main(){
    int n, m, f, t, j, min, min_i, s, k;
    int** a;
    min = INT64_MAX;
    system("clear");
    f = -1;
    while(f != 1 && f != 0){
        puts("for random input enter - '1', for manual - '0'");
        int_in(&f);
    }
    if(f == 1){
        n = -1;
        m = -1;
        while(n <= 0)
            n = rand_in();
        while(m <= 0)
            m = rand_in();
        printf("%s %d " "", "n =", n);
        a = (int**)malloc(n * sizeof(int*));
        for(int i = 0;i < n;i++){
            j = 0;
            m = 1;
            while(1){
                t = rand_in();
                if(t != 0){
                    a[i] = (int*)realloc(a[i], m * sizeof(int));
                    a[i][j] = t;
                    m++;
                    j++;
                }
                else{
                    a[i] = (int*)realloc(a[i], m * sizeof(int));
                    a[i][j] = t;
                    break;
                }
            }
        }
        puts("\n");
        for(int i = 0;i < n;i++){
            j = 0;
            while(1){
                printf("%d " "", a[i][j]);
                if(a[i][j] == 0)
                    break;
                j++;
            }
            puts("\n");
        }
    }
    else{
        puts("Please enter how many rows do you want:");
        int_in(&n);
        a = (int**)malloc(n * sizeof(int*));
        puts("Please enter data:");
        for(int i = 0;i < n;i++){
            j = 0;
            m = 1;
            while(1){
                int_in(&t);
                if(t != 0){
                    a[i] = (int*)realloc(a[i], m * sizeof(int));
                    a[i][j] = t;
                    m++;
                    j++;
                }
                else{
                    a[i] = (int*)realloc(a[i], m * sizeof(int));
                    a[i][j] = t;
                    break;
                }
            }
        }
        for(int i = 0;i < n;i++){
            j = 0;
            while(1){
                printf("%d " "", a[i][j]);
                if(a[i][j] == 0)
                    break;
                j++;
            }
            puts("\n");
        }
    }
    puts("-------------------------------------");
    for(int i = 0;i < n;i++){
        j = 0;
        k = 0;
        while(1){
            if(i % 2 != 0)
                if(a[i][j] < min){
                    min = a[i][j];
                    min_i = j;
                }
            if(a[i][j] == 0){
                s = j + 1;
                break;
            }
            j++;
        }
        for(j = 0;j < s;j++)
            if(a[i][j] == min)
                k++;
        if(i % 2 != 0)
            for(int l = 0;l < k;l++)
                delete(a[i], min_i, s);
    }
    for(int i = 0;i < n;i++){
        j = 0;
            while(1){
                printf("%d " "", a[i][j]);
                if(a[i][j] == 0)
                    break;
                j++;
            }
            puts("\n");
        }
    free(a);
return 0;}