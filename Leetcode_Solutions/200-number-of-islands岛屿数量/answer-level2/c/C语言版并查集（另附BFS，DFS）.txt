### 解题思路
主要练习了并查集算法，顺带BFS和DFS
并查集算法用来进行集合间的操作比较方便，比如判断两个元素是否属于同一集合，进行集合的合并等。

（其实代码还应该进行路径压缩简化根节点的查找）
### 代码

```c
#define DIR 2
#define ROW 0
#define COL 1

int direct[2][2]={
    1,0,
    0,1
};

/*
    找到根节点 
*/

int Find(int** parent, int i, int j, int row, int col){
    if(parent[i][j]==-1){
        return i*col+j;
    }
    return Find(parent,parent[i][j]/col,parent[i][j]%col,row,col);
}

/*

    进行并查集的合并
    合并条件：没有相同的根节点

    根节点不同时，最终根节点由parent更小的根节点决定

*/

void Union(int** parent, int posi, int posj, int newi, int newj, int row, int col, int* ans){
    int pos_root=Find(parent,posi,posj,row,col);
    int new_root=Find(parent,newi,newj,row,col);
    if(pos_root==new_root){
        return ;
    }
    if(pos_root<new_root){
        parent[new_root/col][new_root%col]=pos_root;
    }else{
        parent[pos_root/col][pos_root%col]=new_root;
    }
    *ans=*ans-1;
}

/*
    parent用来保存对应节点的父亲节点，parent[i][j]==-1时表示(i,j)就是根节点
*/

int numIslands(char** grid, int gridSize, int* gridColSize){
    if(gridSize==0 || *gridColSize==0){
        return 0;
    }
    int ans=gridSize*(*gridColSize);
    int** parent=(int**)malloc(sizeof(int*)*gridSize);
    for(int i=0;i<=gridSize-1;i++){
        parent[i]=(int*)malloc(sizeof(int)*(*gridColSize));
        memset(parent[i],-1,sizeof(int)*(*gridColSize));       
    }
    for(int i=0;i<=gridSize-1;i++){
        for(int j=0;j<=*gridColSize-1;j++){
            if(grid[i][j]=='1'){
                for(int dir=0;dir<=DIR-1;dir++){
                    int newi=i+direct[dir][ROW];
                    int newj=j+direct[dir][COL];
                    if((newi<=gridSize-1) && (newj<=*gridColSize-1) && (grid[newi][newj]=='1')){
                        Union(parent,i,j,newi,newj,gridSize,*gridColSize,&ans);
                    }
                }
            }
            else if(grid[i][j]=='0'){
                ans--;
            }
        }
    }
    return ans;
}

```




DFS


```c
#define Dir 4
#define Left 0
#define Right 1

int directions[2][4]={
    -1,1,
    0,0,
    0,0,
    -1,1
};

void dfs(char** grid, int posi, int posj, int row, int col, int** marked){
    marked[posi][posj]=1;
    for(int i=0;i<=Dir-1;i++){
        int newi=posi+directions[Left][i];
        int newj=posj+directions[Right][i];
        if((newi>=0 && newi<=row-1) && (newj>=0 && newj<=col-1) && marked[newi][newj]==0 && grid[newi][newj]=='1'){
            dfs(grid,newi,newj,row,col,marked);
        }
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    int** marked=(int**)malloc(sizeof(int*)*(gridSize));
    int ans=0;
    for(int i=0;i<=gridSize-1;i++){
        marked[i]=(int*)malloc(sizeof(int)*(*gridColSize));
        memset(marked[i],0,sizeof(int)*(*gridColSize));
    }    
    for(int i=0;i<=gridSize-1;i++){
        for(int j=0;j<=*gridColSize-1;j++){
            if(marked[i][j]==0 && grid[i][j]=='1'){
                ans++;
                dfs(grid,i,j,gridSize,*gridColSize,marked);
            }
        }
    }
    return ans;
}


```

BFS

```c
#define Dir 4
#define Left 0
#define Right 1

int direct[2][4]={
    -1,1,0,0,
    0,0,-1,1
};

typedef struct{
    int posi;
    int posj;
}Queue;

int numIslands(char** grid, int gridSize, int* gridColSize){
    int ans=0;
    int** marked=(int**)malloc(sizeof(int*)*gridSize);
    for(int i=0;i<=gridSize-1;i++){
        marked[i]=(int*)malloc(sizeof(int)*(*gridColSize));
        memset(marked[i],0,sizeof(int)*(*gridColSize));
    }
    Queue* queue=(Queue*)malloc(sizeof(Queue)*(gridSize*(*gridColSize)));
    int pointF,pointE;
    for(int i=0;i<=gridSize-1;i++){
        for(int j=0;j<=(*gridColSize)-1;j++){
            if(grid[i][j]=='1' && marked[i][j]==0){
                ans++;
                queue[0].posi=i;queue[0].posj=j;
                pointF=0;pointE=0;
                marked[i][j]=1;
                while(pointE>=pointF){
                    int tempi=queue[pointF].posi;
                    int tempj=queue[pointF].posj;
                    pointF++;
                    for(int dir=0;dir<=Dir-1;dir++){
                        int newi=tempi+direct[Left][dir];
                        int newj=tempj+direct[Right][dir];
                        if((newi>=0 && newi<=gridSize-1) && (newj>=0 && newj<=(*gridColSize-1)) && marked[newi][newj]==0 && grid[newi][newj]=='1'){
                            pointE++;
                            queue[pointE].posi=newi;
                            queue[pointE].posj=newj;
                            marked[newi][newj]=1;
                        }
                    }

                }
            }
        }
    }    
    return ans;
}

```