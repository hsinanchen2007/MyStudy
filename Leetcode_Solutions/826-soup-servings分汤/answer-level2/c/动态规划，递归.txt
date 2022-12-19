### 解题思路
4种分配方式都是25的倍数，除以25之后，4种分配方式表示为(4, 0), (3, 1), (2, 2), (1, 3),
使用动态规划，状态转换方程为：dp(i, j) = (dp(i - 4, j) + dp(i - 3, j - 1) + dp(i - 2, j - 2) + dp(i - 1, j - 3)) / 4
另外为提升性能，用一个数组来缓存中间计算结果。

### 代码

```c

double tmp[5000][5000];

double dp(int a, int b)
{
    double res = 0;

    if (a <= 0) {
        if (b > 0)
            return 1;
        else
            return 0.5;
    } else if (b <= 0) {
        return 0;
    }
    if (tmp[a][b] > 0)
        return tmp[a][b];

    res = (dp(a - 4, b) + dp(a - 3, b - 1) + dp(a - 2, b - 2) + dp(a - 1, b - 3)) / 4;
    tmp[a][b] = res;
    return res;
}

double soupServings(int N){
    if (N >= 4850)
        return 1;

    N = N / 25 + ((N % 25) > 0 ? 1 : 0);
    return dp(N, N);
}
```