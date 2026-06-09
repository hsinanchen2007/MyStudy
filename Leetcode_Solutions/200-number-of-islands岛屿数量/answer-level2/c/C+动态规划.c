思路: 将所有连接的岛屿标志上相同的编号, 最后被标记为最大的编号即为岛屿数量. (运行速度占用99.94%).
int landCnt = 1;
char tmpArray[300][300] = {0};

void setLandCount(char **grid, int gridSize, int* gridColSize, int i, int j){
    
    if (grid[i][j] != '0' && tmpArray[i][j] == 0){
        tmpArray[i][j] = landCnt;
        if (i > 0){
            setLandCount(grid, gridSize,gridColSize,i-1, j);
        }
        if (i < gridSize-1){
            setLandCount(grid, gridSize,gridColSize,i+1, j);
        }
        if (j > 0){
            setLandCount(grid, gridSize,gridColSize,i, j-1);
        }
        if (j < *gridColSize-1){
            setLandCount(grid, gridSize,gridColSize,i, j+1);
        }
    }
}

int numIslands(char **grid, int gridSize, int* gridColSize){

    int len = gridSize *(*gridColSize);
    if (0 == gridSize || 0 == * gridColSize){
        return 0;
    }
    landCnt = 1;
    memset(&tmpArray[0][0],0, 300*300);
    for (int i=0; i < gridSize; i++){
        for(int j =0; j < * gridColSize; j++){
            if (grid[i][j] != '0' && tmpArray[i][j] == 0){
                setLandCount(grid, gridSize,gridColSize,i, j);
                landCnt++;
            }
        }
    }

    return landCnt - 1;
}
