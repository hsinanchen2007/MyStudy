### 解题思路
动态规划模板题
不难发现到达每个方块的方法数，为到达其上方和左方相邻方块的方法数之和。
要想继续节约空间，可以使用**滚动数组**，感兴趣的可以相关资料。

![image.png](https://pic.leetcode-cn.com/3991c59d72046af3a7acef3cf174039cacd5b231e87a2e040b530505630af28f-image.png)

### 代码

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        int f[100][100];
        // 动规数组初始化
        for(int i = 0; i < m; i ++)
            f[0][i] = 1;
        for(int j = 0; j < n; j ++)
            f[j][0] = 1;
        // 动态规划
        for(int i = 1; i < m; i ++)
            for(int j = 1; j < n; j ++)
                f[j][i] = f[j - 1][i] + f[j][i - 1];
        return f[n - 1][m - 1];
    }
};
```