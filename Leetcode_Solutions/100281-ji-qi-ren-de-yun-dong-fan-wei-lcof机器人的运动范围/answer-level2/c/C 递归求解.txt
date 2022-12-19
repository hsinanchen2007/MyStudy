```
int matchK(int row, int col)
{
    int val = 0;
    while (row != 0) {
        val += row % 10;
        row = row / 10;
    }
    
    while (col != 0) {
        val += col % 10;
        col = col /10;
    }
    
    return val;
}

int searchNum(int m, int n, int row, int col, int k, int flag[][n])
{
    int num = 0;
    if (row < 0 || row >= m || col < 0 || col >= n || flag[row][col] == 1) {
        return 0;
    }
    flag[row][col] = 1;

    if (matchK(row, col) > k) {
        return num;
    }
    num++;

    return (num + searchNum(m, n, row + 1, col, k, flag) + searchNum(m, n, row - 1, col, k, flag) +
                  searchNum(m, n, row, col + 1, k, flag) + searchNum(m, n, row, col - 1, k, flag));
}

int movingCount(int m, int n, int k){
    int num = 0;
    int flag[m][n];
    memset(flag, '0', sizeof(flag));
    num = searchNum(m, n, 0, 0, k, flag);
    return num;
}
```
