# 思路
不失一般性,假设第i行第j列的路径数量为f[i,j]. 那么, 第i行第j列 只能从
1. i-1 行,j列向下走
2. i行,j-1 列向右走
所以f[i,j]的 状态可以表示为 f[i,j] = f[i -1,j] + f[i , j-1];

![213.png](https://pic.leetcode-cn.com/2fde5c2aa75332a10e5da069c4d7becd2a6e5e23c84911a82ece91bb48537ff8-213.png)

```
class Solution {
public:
    int uniquePaths(int m, int n) {
        const int N = 110;
        int f[N][N];
        memset(f, 0 , sizeof f);
        f[1][1] = 1;
        for(int i = 1; i <= m; i ++ )
            for(int j = 1; j <= n; j++)
            {
                if(i == 1 && j == 1) continue;
                f[i][j] = f[i - 1][j] + f[i][j - 1];
            }

        return f[m][n];
        
    }
};
```
y总牛逼 %%%%%%%%%%

