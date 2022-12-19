### 解题思路
![image.png](https://pic.leetcode-cn.com/ec6e375ac4bea9a6615e4efd597336e7c8f1ab9f357af4bd606b5bc84cdf825c-image.png)


### 代码

```c
/* 机器人的运动范围 */
int getNumSum(int x)
{
    int sum = 0;
    while (x != 0) {
        sum += x % 10;
        x /= 10;
    }

    return sum;
}

int xySum(int x, int y)
{
    return getNumSum(x) + getNumSum(y);
}

int g_ans = 0;
void solve(int m, int n, int x, int y, int k, int **flag)
{
    // 边界裁剪
    if ((x >= m) || (x < 0) || (y >= n) || (y < 0)) {
        return;
    }

    // 走过的不在走， 坐标位数和不满足情况不走
    if ((flag[x][y] == 1) || (xySum(x, y) > k)) {
        return;
    }

    flag[x][y] = 1;
    g_ans++;
    solve(m, n, x + 1, y, k, flag);
    solve(m, n, x - 1, y, k, flag);
    solve(m, n, x, y + 1, k, flag);
    solve(m, n, x, y - 1, k, flag);

    return;
}

int movingCount(int m, int n, int k)
{
    int **flag = (int **)malloc(sizeof(int *) * m); // 标记已经走过的格子
    for (int i = 0; i < m; i++) {
        flag[i] = (int *)malloc(sizeof(int) * n);
        memset(flag[i], 0x0, sizeof(int) * n);
    }

    g_ans = 0;
    solve(m, n, 0, 0, k, flag);

    return g_ans;
}
```