思路：模拟棋盘，时间复杂度 O(n^2)
1. 将 moves 填入虚拟棋盘， a 为 -1 ， b 为 1
2. 对角线 和 横纵向 分别判断胜利条件
3. 无胜者情况

```C
char * tictactoe(int** moves, int movesSize, int* movesColSize){
    // 将 moves 填入虚拟棋盘， a 为 -1 ， b 为 1
    int s[3][3] = {0};
    for (int i = 0; i < movesSize; i++) {
        int x = moves[i][0], y = moves[i][1];
        if (i & 1) s[x][y]++;
        else s[x][y]--;
    }
    // 对角线判断
    int sumD1 = s[0][0] + s[1][1] + s[2][2];
    int sumD2 = s[0][2] + s[1][1] + s[2][0];
    if (sumD1 ==  3 || sumD2 ==  3) return "B";
    if (sumD1 == -3 || sumD2 == -3) return "A";
    // 横向、纵向判断
    for (int i = 0; i < 3; i++) {
        int sumR = s[i][0] + s[i][1] + s[i][2];
        int sumC = s[0][i] + s[1][i] + s[2][i];
        if (sumR ==  3 || sumC ==  3) return "B";
        if (sumR == -3 || sumC == -3) return "A";
    }
    // 无胜者情况
    return movesSize < 9 ? "Pending" : "Draw";
}
```
