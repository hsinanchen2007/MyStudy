上下底面积非常容易计算, 主要是如何计算侧面积.
我们可以假设一个人从一行头部沿该行行走, 中间上下的累计高度为该行的左右面积, 依次累加各行;列亦如此.
```c
int jump(int a, int b) {
    return a >= b ? a - b : b - a;
}
int surfaceArea(int** grid, int gridSize, int* gridColSize){
    int lrArea = 0, feArea = 0, udArea = 0; /*left right front end up down area*/
    for (int i = 0; i < gridSize; i++) {
        lrArea += grid[i][0]; /*从地面跳到该行第一个柱体*/
        feArea += grid[0][i]; /*从地面跳到该列第一个柱体*/
        for (int j = 0; j < gridSize - 1; j++) { /*注意边界是 == gridSize - 2*/
            lrArea += jump(grid[i][j], grid[i][j + 1]); /*沿行行走, 累计jump高度*/
            feArea += jump(grid[j][i], grid[j + 1][i]); /*沿列行走, 累计jump高度*/
            if (grid[i][j])
                udArea += 2; /*按行计算上下底面积*/
        }
        lrArea += grid[i][gridSize - 1]; /*从该行最后一个柱体跳到地面*/
        feArea += grid[gridSize - 1][i]; /*从该列最后一个柱体跳到地面*/
        if (grid[i][gridSize - 1])
            udArea +=2; /*该行最后一个柱体*/
    }
    return lrArea + feArea + udArea;
}
```