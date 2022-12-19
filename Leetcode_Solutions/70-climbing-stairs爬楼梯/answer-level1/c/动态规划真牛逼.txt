### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/fd03b31069a27eb68be58827ccd5d63043dd0e4ebe99773ea8bd5272e62a7278-image.png)
1)一开始我用的是递归的解决办法，结果是TLE
2) 第二次用的dp的方法，问题得到了解决

dp算法适用于什么场景，这个需要好好分析下。

### 代码

```c
int climbStairs(int n){
    int *dp = calloc(n + 1, sizeof(int));

    if (n == 1) {
        return 1;
    }

    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}
```