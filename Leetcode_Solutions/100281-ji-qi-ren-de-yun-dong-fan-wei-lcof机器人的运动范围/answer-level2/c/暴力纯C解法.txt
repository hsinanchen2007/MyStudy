### 解题思路
1、设置一个flag矩阵
2、特殊处理矩阵[0][0]位置，起点，标记为已遍历
3、暴力遍历矩阵，判断若左边，或上面已标记，同时数值比较也满足条件，则累加计数

### 代码

```c
int CalsSum(int x, int y)
{
    int tmp;
    int sumX = 0;
    int sumY = 0;

    tmp = x;
    while (tmp != 0) {
        sumX += tmp % 10;
        tmp = tmp / 10;
    }
    tmp = y;
    while (tmp != 0) {
        sumY += tmp % 10;
        tmp = tmp / 10;
    }
    return sumX + sumY;
}

int movingCount(int m, int n, int k){
    int i, j, sum, tmp;
    int** flag = NULL;
    if (k < 0 || m < 0 || n < 0) {
        return 0;
    }
    flag = (int**)malloc(sizeof(int*) * m);
    if (flag == NULL) {
        return 0;
    }
    for (i = 0; i < m; i++) {
        flag[i] = (int*)malloc(sizeof(int) * n);
        if (flag[i] == NULL) {
            return 0;
        }
        memset(flag[i], 0, sizeof(int) * n);
    }
    
    flag[0][0] = 1;
    sum = 1;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            tmp = CalsSum(i, j);
            if (tmp <= k) {
                if ((i - 1 >= 0 && flag[i - 1][j] == 1) ||
                    (j - 1 >= 0 && flag[i][j - 1] == 1)) {
                    sum++;
                    flag[i][j] = 1;
                }
            } 
        }
    }
    return sum;
}
```