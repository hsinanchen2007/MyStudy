### 解题思路
执行用时 :28 ms, 在所有 C 提交中击败了33.70%的用户  
内存消耗 :6.9 MB, 在所有 C 提交中击败了100.00%的用户  

使用与grid二维数组相同大小的flag数组，flag数组用来记录grid中的元素是否被遍历过，防止无穷递归。

### 代码

```c
int maxArea(int** grid, int gridSize, int* gridColSize, int** flag, int i, int j){
    int len = 0;
    if(grid[i][j] == 1 && flag[i][j] == 0){
        len++;
        flag[i][j] = 1;
        // up
        if(i-1>=0 && grid[i-1][j]==1 && flag[i-1][j] == 0){
            len += maxArea(grid, gridSize, gridColSize, flag, i-1, j);
        }
        // down
        if(i+1<gridSize && grid[i+1][j]==1 && flag[i+1][j] == 0){
            len += maxArea(grid, gridSize, gridColSize, flag, i+1, j);
        }
        //left
        if(j-1>=0 && grid[i][j-1]==1 && flag[i][j-1] == 0){
            len += maxArea(grid, gridSize, gridColSize, flag, i, j-1);
        }
        //right
        if(j+1<gridColSize[i] && grid[i][j+1]==1 && flag[i][j+1] == 0){
            len += maxArea(grid, gridSize, gridColSize, flag, i, j+1);
        }
    }
    return len;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int i, j, temp, max = 0;
    // flag数组标记grid的岛屿是否已遍历
    int** flag = (int**)malloc(sizeof(int*)*gridSize);
    for(i=0; i< gridSize; i++){
        flag[i] = (int*)malloc(sizeof(int)*gridColSize[i]);
        memset(flag[i], 0, gridColSize[i]*sizeof(int));
    }
    // 对grid里每个元素进行判断
    for(i=0; i< gridSize; i++){
        for(j=0; j<gridColSize[i]; j++){
            temp = maxArea(grid, gridSize, gridColSize, flag, i, j);
            max = max>temp?max:temp;
        }
    }

    return max;
}

```