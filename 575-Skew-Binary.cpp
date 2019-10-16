
#include<stdio.h>
#include<math.h>
#include<string.h>

int main(){
    long sum,len,i,k,n,p;
    char str[100];

    while( scanf("%s",str) ){
        if( str[0] == '0' ) break;
        len = strlen(str);
        sum = 0;
          k = 0;
        for( i = len-1 ; i >= 0 ; i-- ){
            n = str[i]-'0';
            p =(long) pow(2,k+1);
            sum+=( n * ( p - 1 ) );
            k++;
        }
        printf("%ld\n",sum);

    }
    return 0;
}