#include <stdio.h>
#include<string.h>

const int MAX = 120;

char image[MAX+1][MAX+1];
int N,M;

int dr[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
int dc[8] = {-1,  0,  1, -1, 1, -1, 0, 1};

int valid(int r, int c) {
    if (r < 0 || c < 0 || r >= N || c >= M)
        return 0;
    return 1;
}

void DFSvisit(int r, int c) {
    int nr, nc, i;
    image[r][c] = '*';
    for (i = 0; i < 8; i++) {
        nr = r + dr[i];
        nc = c + dc[i];
        if (valid(nr, nc) && '@' == image[nr][nc])
            DFSvisit(nr, nc);
    }
}

int DFS() {
    int r, c, count = 0;
    for (r = 0; r < N; r++)
        for (c = 0; c < M; c++)
            if ('@' == image[r][c]) {
                count++;
                DFSvisit(r, c);
            }
    return count;
}

int main() {


    int i, count, kase = 0;
    while (2 == scanf("%d%d", &N,&M)) {
        if(N == 0 && M == 0 ) break;
        for (i = 0; i < N; i++)
            scanf("%s", image[i]);
            ++kase;
            count = DFS();
            printf("%d\n",count);
    }
    return 0;
}