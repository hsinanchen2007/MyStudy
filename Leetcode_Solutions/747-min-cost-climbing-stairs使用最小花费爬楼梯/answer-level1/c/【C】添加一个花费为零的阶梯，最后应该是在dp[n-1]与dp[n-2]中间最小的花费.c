1.由于题目有两个起点，可以从1阶梯开始，也可以从2阶梯开始，同时最后可以走两步，直接登顶
2.在序列中隐形添加一个阶梯，花费为零
3.dp[n-1] 未必是最优解，可能是dp[n-2]
4.在隐形添加一个花费为0的阶梯后则最优解是dp[n]

```
#define max(a,b)    (((a) > (b)) ? (a) : (b))
#define min(a,b)    (((a) < (b)) ? (a) : (b))

int minCostClimbingStairs(int* cost, int costSize)
{
    if (cost == NULL || costSize <= 0) {
        return 0;
    }

    if (costSize == 1) {
        return cost[0];
    }
    if (costSize == 2) {
        return min(cost[0], cost[1]);
    }

    int *dp = (int *)malloc(sizeof(int) * (costSize + 1));
    if (dp == NULL) {
        return 0;
    }
    memset(dp, 0, costSize + 1);
    dp[0] = cost[0]; // 从第一阶梯开始
    dp[1] = cost[1]; // 从第二阶梯开始
//     printf("dp[%d] = %d\r\n", 0, dp[0]);
//     printf("dp[%d] = %d\r\n", 1, dp[1]);
    for (int i = 2; i <= costSize; ++i) {
        if (i == costSize) {
            dp[i] = min(dp[i - 2], dp[i - 1]);
        } else {
            int oneChoice = dp[i - 2] + cost[i];
            int anotherChoice = dp[i - 1] + cost[i];
            dp[i] = min(oneChoice, anotherChoice) ;
        }
/*        printf("dp[%d] = %d\r\n", i, dp[i]);*/
    }

    int result = dp[costSize];
    free(dp);
    dp = NULL;
    return result;
}

```
