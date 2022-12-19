```
//          x-1,y 
//  x,y-1   x,y     x,y+1
//          x+1,y
//方向数组，它表示了相对于当前位置的4个方向的横、纵坐标的偏移量，是一个常见的技巧
int directions[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
//从坐标（i,j）开始进行深度优先遍历
void DFS(int i,int j,char** grid,int Row,int Col,int** visited) {
    visited[i][j] = 1;
    //得到4个方向的坐标
    for(int k = 0;k < 4;k++) {
        int newX = i + directions[k][0];
        int newY = j + directions[k][1];
        //如果不越界 && 没有被访问过 && 还要是陆地
        if(newX >= 0 && newX < Row && newY >= 0 && newY < Col && grid[newX][newY] == '1' && !visited[newX][newY]) {
                DFS(newX,newY,grid,Row,Col,visited);
        }
    }
}
int numIslands(char** grid, int gridSize, int* gridColSize){
    int Row = gridSize;
    int Col = *gridColSize;
    if(Row == 0) {
        return 0;
    }
    if(*gridColSize == 0) {
        return 0;
    }
    int islandCount = 0;
    //标记数组，标记grid的坐标对应的各自是否被访问过
    int** visited = (int**)malloc(sizeof(int*)*Row);
    for(int i = 0;i < Row;i++) {
        visited[i] = (int*)malloc(sizeof(int)*Col);
    }
    for(int i = 0;i < Row;i++) {
        for(int j = 0;j < Col;j++) {
            visited[i][j] = 0;
        }
    }
    
    for(int i = 0;i < Row;i++) {
        for(int j = 0;j < Col;j++) {
            //如果是岛屿中的一个点，并且没有被访问过
            //就进行深度优先遍历
            if(!visited[i][j] && grid[i][j] == '1') {
                islandCount++;
                DFS(i,j,grid,Row,Col,visited);
            }
        }
    }
    return islandCount;
}


```
