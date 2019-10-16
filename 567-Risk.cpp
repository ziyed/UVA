#include<iostream.h>
#include<stdio.h>
#define INF 9999

int c[30];
int d[30];
int q[100];
int head,tail;
int adj[30][30];


int empty(){
    if(head == tail ) return 1;
    else return 0;
}

void init(){
    head=tail=0;   
}

void addq(int val){
    q[++tail]=val;
}

int delq(){
    return q[++head];
}

int bfs(int s,int k){
    int u,v;
   
    for(u = 1 ; u < 21 ;u++ ){
        c[u]=0;
        d[u]=INF;
    }

    init();

    c[s]=1;
    d[s]=0;
    addq(s);

    while(empty()==0){
        u = delq();
        for( v = 1 ; v < 21 ; v++ ){
            if( c[v] == 0 && adj[u][v] < INF ){
                c[v]=1;
                d[v] = d[u]+1;
                addq(v);
            }
        }
        c[u]=1;
    }

    return d[k];
}

int main(){
    int N,i,s,j,k,d,l,temp,val,start,dest,need,count;
    count=1;
  
    while(scanf("%d",&N)== 1){

        for(i = 1 ; i < 21 ; i++ )
            for( j = 1 ; j < 21 ; j++ )
                adj[i][j]=INF;

        s=1;
        for(i = 0 ; i < N ; i++ ){
            scanf("%d",&d);
            adj[s][d]=1;
            adj[d][s]=1;
        }

        for( s = 2 ; s < 20 ; s++ ){
            scanf("%d",&N);
            for(i = 0 ; i < N ; i++ ){
                scanf("%d",&d);
                adj[s][d]=1;
                adj[d][s]=1;
            }
        }
        printf("Test Set #%d\n",count);
        scanf("%d",&val);
        for( i = 0 ; i < val ; i++ ){
            scanf("%d%d",&start,&dest);
            need = bfs(start,dest);
            printf("%2d to %2d: %d\n",start,dest,need);
        }
        printf("\n");
        count++;
    }
    return 0;
}