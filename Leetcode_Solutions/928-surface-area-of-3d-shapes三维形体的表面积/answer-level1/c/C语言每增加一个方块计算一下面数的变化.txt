### 解题思路
这题最大的难度是读懂题意。。。
可以模拟一下增加方块，逐步计算面数的变化。每增加一个方块，总的面数增加6，但是如果下面还有一个的话，就会减少两个面（前面和左面同理）。

### 代码

```c
int surfaceArea(int** grid, int gridSize, int* gridColSize){
    int i, j, k, res = 0;
    for(i=0; i<gridSize; i++){
        for(j=0; j<gridColSize[i]; j++){
            for(k=0; k<grid[i][j]; k++){
                res += 6;
                // 下面相邻
                if(k>0){
                    res -= 2;
                }
                // 前面相邻
                if(i>0 && grid[i-1][j]>k){
                    res -= 2;
                }
                // 左面相邻
                if(j>0 && grid[i][j-1]>k){
                    res -= 2;
                }
            }
        }
    }
    return res;
}

```