#include<stdio.h>
#include<string.h>

int isPrime(int num) {
    int i;
    if( num == 1 ) return 0;
    if(num == 2 ) return 1;

    for( i = 2 ; i < num ; i++ ){
        if(num%i==0) return 0;
    }
    return 1;
}

struct number{
    int fre;
}val[200];



int main(){

    int t,i,j,len,n,k;
    char str[3000],data[3000];

    scanf("%d",&t);
    for( i = 1 ; i <= t ; i++ ){
        scanf("%s",str);
        len = strlen(str);
        for( j = 46 ; j < 130 ; j++ )
            val[j].fre=0;
       
        for( j = 0 ; j < len ; j++ ){
            n = (int)str[j];
            val[n].fre++;
        }
        k = 0;
        for( j = 46 ; j < 130 ; j++ ){
            if( val[j].fre != 0 ){
                if( isPrime(val[j].fre))
                    data[k++]=(char)j;

            }
            else continue;
        }
       
        data[k]='\0';

       
       
        len = strlen(data);

        if( len == 0 ){
            printf("Case %d: empty\n",i);
        }
        else{
            printf("Case %d: ",i);
            for(j = 0 ; j < len ; j++ )
                printf("%c",data[j]);
            printf("\n");
        }

   
    }
    return 0;
}