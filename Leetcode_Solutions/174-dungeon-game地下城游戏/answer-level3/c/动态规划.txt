其实逻辑很简单，使用动态规划来解决。
从最右下角要救出开始，可以知道我们要到右下角的最小值
右下角知道了，又可以辐射到最后一行和最后一列
然后再依次倒退，看下每次到底是否右边还是下边的值小，就从哪里过来，一直反推到[0][0]
```
int calculateMinimumHP(int dungeon, int dungeonSize, int* dungeonColSize) {
    #define GET_MIN_REQUEST(req, cur) ((req) <= (cur) ? 1 : (req) - (cur))

    if (dungeon == NULL || dungeonColSize == NULL || *dungeonColSize == 0 || dungeonSize == 0 ) {
        return 0;
    }

    int row = dungeonSize;
    int col = *dungeonColSize;
    int** minHp = (int**)malloc(sizeof(int*) * row);
    for(int i = 0; i < row; i++) 
        minHp[i] = (int *)malloc(sizeof(int) * col);
   
    minHp[row - 1][col - 1] = (dungeon[row -1][col -1] >= 0) ? 1 : (1 - dungeon[row -1][col -1]);

    for(int i = col - 2; i >= 0; i--) 
        minHp[row - 1][i] = GET_MIN_REQUEST(minHp[row - 1][i + 1],  dungeon[row - 1][i]);

    for(int i = row - 2; i >= 0; i--) 
        minHp[i][col - 1] = GET_MIN_REQUEST(minHp[i + 1][col - 1],  dungeon[i][col - 1]);

    for(int i = row - 2; i >= 0; i--) {
        for(int j = col - 2; j >= 0; j--) {
            int min = minHp[i + 1][j] < minHp[i][j + 1] ? minHp[i + 1][j] : minHp[i][j + 1];
            minHp[i][j] = GET_MIN_REQUEST(min, dungeon[i][j]);
        }
    }
  
    int result = minHp[0][0];  
    for(int i = 0; i < row; i++) {
        free(minHp[i]);
    }
    free(minHp);
    return result;
}

```