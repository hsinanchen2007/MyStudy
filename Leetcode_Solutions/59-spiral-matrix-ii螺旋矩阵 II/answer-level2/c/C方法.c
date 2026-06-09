模拟填值。
```
int dir[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // 每次变方向后x轴和y轴的变化
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    int i, j;
    int turnTimes;
    int **output;
    output = (int **)malloc(n * sizeof(int *));
    *returnSize = n;
    turnTimes = 2 * n - 1; // 计算出变方向的总的次数
    returnColumnSizes[0] = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        output[i] = (int *)malloc(n * sizeof(int));
        memset(output[i], 0, n * sizeof(int));
        output[0][i] = i + 1;
        returnColumnSizes[0][i] = n;
    }
    int change = 0;
    int x = 0, y = n - 1;
    int a, b;
    int num = n;
    int turn;
    int cnt = n + 1;
    
    for (i = 0; i < turnTimes - 1; i++) { // 按方向变化循环，每次循环后x和y的改变方式发生变化
        turn = i & 0x03;
        a = dir[turn][0];
        b = dir[turn][1];
        if (turn % 2 == 0) {
            num--;
        } 
        for (j = 0; j < num; j++) {
            x += a;
            y += b;
            output[x][y] = cnt;
            cnt++;
        }

    }
    return output;
}
```
