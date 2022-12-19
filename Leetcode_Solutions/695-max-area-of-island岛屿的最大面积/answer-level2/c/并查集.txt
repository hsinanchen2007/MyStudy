### 解题思路
使用DFS,BFS和并查集都可以做题，此处使用并查集

### 代码

```c
typedef struct{
    int size;
    int parent;
}isLand;

int getParent(isLand** parent, int i, int j, int row, int col){
    int now=i*col+j;
    if(parent[i][j].parent!=-1){
        now=getParent(parent,(parent[i][j].parent)/col,(parent[i][j].parent)%col,row,col); 
    }
    return now;
}

void Union(isLand** parent, int posi, int posj, int nexti, int nextj, int row, int col){
    int parent_pos=getParent(parent,posi,posj,row,col);
    int parent_next=getParent(parent,nexti,nextj,row,col);
    if(parent_pos==parent_next){
        return;
    }   
    int num=0;
    if(parent_next>parent_pos){
        parent[parent_next/col][parent_next%col].parent=parent_pos;
        num=parent[parent_next/col][parent_next%col].size+2;
        parent[parent_pos/col][parent_pos%col].size+=num;
    }
    else{
        parent[parent_pos/col][parent_pos%col].parent=parent_next;
        num=parent[parent_pos/col][parent_pos%col].size+2;
        parent[parent_next/col][parent_next%col].size+=num;
    }
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int ans=-2;
    isLand** parent=(isLand**)malloc(sizeof(isLand*)*(gridSize));
    for(int i=0;i<=gridSize-1;i++){
        parent[i]=(isLand*)malloc(sizeof(isLand)*(*gridColSize));
        memset(parent[i],-1,sizeof(isLand)*(*gridColSize));        
    }

    for(int i=0;i<=gridSize-1;i++){
        for(int j=0;j<=*gridColSize-1;j++){
            if(grid[i][j]==1){
                if((i+1)<=(gridSize-1) && grid[i+1][j]==1){
                    Union(parent,i,j,i+1,j,gridSize,*gridColSize);
                }
                if((j+1)<=(*gridColSize-1) && grid[i][j+1]==1){
                    Union(parent,i,j,i,j+1,gridSize,*gridColSize);
                }
            }
        }
    }
    for(int i=0;i<=gridSize-1;i++){
        for(int j=0;j<=*gridColSize-1;j++){
            if(grid[i][j]==1 && parent[i][j].size>ans){
                ans=parent[i][j].size;
            }
        }
    }
    return ans+2;
}
```