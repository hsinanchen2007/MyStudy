两行，n列数组表示所有情况：
一共0~n个台阶说明要么从第n-1个台阶跨过去的。要么是从第n个跨过去的。
dp[0][i]行代表从第i-1个台阶跨过去的值。
dp[1][i]行代表从第i个台阶跨过去的值。

```
#define MIN(a, b)  (((a)<(b)) ? (a) : (b))

int minCostClimbingStairs(int* cost, int costSize){
    int *dp[2];
    for(int i = 0; i < 2; i++)
        dp[i] = malloc(sizeof(int) * costSize);
    
    dp[0][0] = cost[0];
    dp[1][0] = cost[0];
    dp[0][1] = cost[0];
    dp[1][1] = cost[1];

    for(int i = 2; i < costSize; i++)
    {
        dp[0][i] = dp[1][i-1];
        dp[1][i] = cost[i] + MIN(dp[0][i-1], dp[1][i-1]);
    }
    return MIN(dp[0][costSize-1], dp[1][costSize-1]);
}
```


以[1, 100, 1, 1, 1, 100, 1, 1, 100, 1]为例：
![图片.png](https://pic.leetcode-cn.com/e8eac74a9b22c845c62137555c3e57bfffea8b2c231673709ae819d3ebf3069b-%E5%9B%BE%E7%89%87.png)
