```
int find(int i,int*roots){
    while(i!=roots[i])i=roots[i];
    return i;
}
void Union(int x,int y,int *count,int *roots,int *rank){
    int rootx=find(x,roots);
    int rooty=find(y,roots);
    if(rootx==rooty)return;
    if(rank[rootx]>rank[rooty]){//记录树高度，进行优化
        roots[rooty]=rootx;
    }else if(rank[rootx]<rank[rooty]){
        roots[rootx]=rooty;
    }else{
        roots[rootx]=rooty;
        rank[rooty]=rank[rooty]+1;
    }
    (*count)--;
}
void dfs(int **M,int i, int j,int MSize,int col);
int findCircleNum(int** M, int MSize, int* MColSize){
    int col=MColSize[0];
    int *roots=malloc(sizeof(int)*MSize);
    int *rank=malloc(sizeof(int)*MSize);
    memset(rank,0,sizeof(int)*MSize);
    int count=MSize;
    for(int i=0;i<MSize;i++){
        roots[i]=i;
        }
    for(int i=0;i<MSize;i++){
        for(int j=0;j<col;j++){
            if(M[i][j]==1&&i!=j){
                Union(i,j,&count,roots,rank);
            }
        }
    }    
    return count;
}

```
广度遍历BFS
```
int findCircleNum(int** M, int MSize, int* MColSize){
    int col=MColSize[0];
    int *visited=malloc(sizeof(int)*MSize);
    memset(visited,0,sizeof(int)*MSize);
    int count=0;
    int *queue=malloc(sizeof(int)*MSize*col);
    int front=0,rear=0;
    for(int i=0;i<MSize;i++){
        if(visited[i]==0){
            queue[rear++]=i;
            while(front!=rear){
                int s=queue[front++];
                visited[s]=1;
                for(int j=0;j<col;j++){
                    if(M[s][j]==1&&visited[j]==0){
                        queue[rear++]=j;
                    }
                }
            }
            count++;
        }
}
    
    return count;
}
```

DFS
```
void dfs(int *visited,int **M,int col,int i){
    visited[i]=1;
    for(int j=0;j<col;j++){
        if(M[i][j]==1&&visited[j]==0){//j与i相连，再去找与j相连的，找不到就返回。
            dfs(visited,M,col,j);
        }
    }
}
int findCircleNum(int** M, int MSize, int* MColSize){
    int col=MColSize[0];
    int *visited=malloc(sizeof(int)*MSize);
    memset(visited,0,sizeof(int)*MSize);
    int count=0;
    for(int i=0;i<MSize;i++){
        if(visited[i]==0){
            dfs(visited,M,col,i);
            count++;
        }
}
    
    return count;
}

```
