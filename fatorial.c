#include <stdio.h>

int fatorial(int x){
    if (x == 0){
        return x = 1;
    }
    else{
        return x * fatorial(x - 1);
    }
}

int main(){
    int num;

    printf("Digite um numero: ");
    scanf("%d",&num);

    printf("\n\n o fatorial de %d e %d",num,fatorial(num));
    return 0;

}