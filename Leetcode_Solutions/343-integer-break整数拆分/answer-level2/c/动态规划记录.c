### 解题思路
先用递归，一直能分割到1，当分割到i的时候，就在下面三个值中，选取一个最大值：之前存放的dp[i]，i*(n-i)和i*（n-i）继续分割后的最大值。
![1.JPG](https://pic.leetcode-cn.com/43120364d06bb369b43e537e1d9f8bb8b104d36185f33d63fb928fa77e16cc54-1.JPG)


### 代码

```c
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int max3(int a, int b, int c)
{
    return max(a, max(b, c));
}

int integerBreak(int n){
    int i = 1;
    int *dp;
    dp = (int *)malloc(sizeof(int) * (n + 1));
    memset(dp, 0, sizeof(int) * (n + 1));

    
    if (n == 1)
        return 1;

    dp[1] = 1;

    for (int i = 2; i <= n; i ++)
    {
        for (int j = 1; j <= i - j; j ++)
        {
            dp[i] = max3(dp[i], j * (i - j), j * dp[i - j]); 
        }
    }

    return dp[n];
}
```