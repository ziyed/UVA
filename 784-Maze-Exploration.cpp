#include<stdio.h>
#include<string.h>
char str[100],temp[5];
char maze[100][100];
int j,ro;

int dr[8] = {-1,0,1,0};
int dc[8] = {0,1,0,-1};

void DFSvisit(int r, int c) {
    int nr, nc, i;
   
    maze[r][c]='#';

    for (i = 0; i < 4; i++) {
        nr = r + dr[i];
        nc = c + dc[i];
        if ( maze[nr][nc] == ' '){
            maze[nr][nc]='#';
            DFSvisit(nr, nc);
        }
    }
}

void DFS() {
    int r,c,ROW,COL;
    for (r = 0; r < j; r++)
        for( c = 0 ; c < ro ; c++)
            if ('*' == maze[r][c]){
               ROW=r;
               COL=c;
            }
          
     DFSvisit(ROW,COL);
       
   
}

int main(){
    int n,k,l,r,c,len;
           
    scanf("%d",&n);
   
    gets(temp);
   
    for( int i = 0 ; i < n ; i++ ){
        j = 0 ;
        ro=0;

        while(gets(str)){
            if( str[0] == '_') break;
            else{
                len = strlen(str);
                if( len > ro ) ro = len;
                strcpy(maze[j++],str);
            }
           
        }
       
        DFS();
       
        for( k = 0 ; k < j ; k++){
            printf("%s",maze[k]);
            printf("\n");
        }
        puts(str);
       
    }
    return 0;
}