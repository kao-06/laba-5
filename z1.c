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
    int n, i, f;
    int* a;
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
        printf("%d \n", n);
        a = (int*) malloc(n * sizeof(int));
        for(int i = 0;i < n;i++)
            a[i] = rand_in();
        for(int i = 0;i < n;i++)
            printf("%d " "", a[i]);
    }
    else{
        puts("Please enter a number of elements that you want to enter:");
        int_in(&n);
        a = (int*) malloc(n * sizeof(int));
        puts("Please enter elements that you want to enter:");
        for(int i = 0;i < n;i++)
            int_in(&a[i]);
        for(int i = 0;i < n;i++)
            printf("%d " "", a[i]);
    }
    i = 0;
    while(1){
        if(a[i] < 0){
            delete(a, i, n);
            n--;
            i--;
        }
        if(i == n - 1)
        break;
        i++;
    }
    puts("\n");
    for(int i = 0;i < n;i++)
        printf("%d " "", a[i]);
    puts("");
    if(n > 0)
        free(a);
return 0;}