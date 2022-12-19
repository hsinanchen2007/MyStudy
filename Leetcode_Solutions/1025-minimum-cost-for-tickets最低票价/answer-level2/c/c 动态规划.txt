### 解题思路
自下而上的动态规划，注意一个细节。有可能7天的cost比1天的cost要低，真够坑的

### 代码

```c
#define MAX 400000
#define DAYS 365

int mincostTickets(int* days, int daysSize, int* costs, int costsSize){
    int dp[DAYS + 1];
    int i;
    int j;
    int dayidx = 0;
    int step[] = {1,7,30};
    dp[0] = 0;
    for (i = 1; i <= days[daysSize - 1]; i++) {
  
        if (dayidx < daysSize && i != days[dayidx]) {
            dp[i] = dp[i - 1];
            continue;
        }

        dp[i] = MAX;
        for (j = 0; j < costsSize; j++) {
            
            if (i <= step[j]) {
                if (dp[i] > costs[j] + dp[0])
                    dp[i] = costs[j];
            }
            if (i > step[j] && dp[i] > costs[j] + dp[i - step[j]])
                dp[i] = costs[j] + dp[i - step[j]];
        }

        dayidx++;
    }

    return dp[i-1];
}
```