#include<stdio.h>
#include<string.h>
#define INF 9999

struct que{
 int row;
 int col;
}q[100];

int adj[9][9];
int d[9][9];
int co[9][9];
int head,tail;

int dr[8]={2,2,1,-1,-2,-2,-1,1};
int dc[8]={-1,1,2,2,1,-1,-2,-2};

int valid(int r, int c){
    if(r < 1 || c < 1 || r > 8  || c > 8 )
        return 0;
    return 1;
}

void init(){
    head=tail=0;
}

void addq(int r , int c){
    q[++tail].row=r;
    q[++tail].col=c;
}

int delq(){
    int val;
    val = ++head;
    return val;
}

int qempty(){
    if(head==tail)
         return 1;
    else
         return 0;
}

void BFS(int row,int col){
    int u,v,valr,valc,r,c;
   
    for( u = 1 ; u < 9 ; u++){
        for( v = 1 ; v < 9 ; v++){
            d[u][v] = INF;
            co[u][v] = 0 ;
        }
    }
   
    init();
   
    co[row][col] = 1;
    d[row][col] = 0;
   
    q[++tail].row=row;
    q[++tail].col=col;
   
   
    while( qempty() == 0 ){
           valr = q[delq()].row;
           valc = q[delq()].col;
           for( v = 0 ; v < 8 ; v++ ){
                r = dr[v]+valr;
                c = dc[v]+valc;
                if( valid( r , c ) == 1 && co[r][c] == 0 ){
                    d[r][c] = d[valr][valc] + 1;
                    co[r][c] = 1;
                    addq(r,c);
                }
           }
          
              
    }
           
}

int main(){

    char s1[5],s2[5];
    int r1,r2,c1,c2,i,j;
   
    while(scanf("%s%s",&s1,&s2) == 2 ){
        c1=1+(s1[0]-'a');
        r1=s1[1]-'0';
        c2=1+(s2[0]-'a');
        r2=s2[1]-'0';
       
        BFS(r1,c1);
       
        printf("To get from %s to %s takes %d knight moves.\n",s1,s2,d[r2][c2]);
               
    }   
    return 0;
}