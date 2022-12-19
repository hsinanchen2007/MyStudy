### 解题思路
此处撰写解题思路

### 代码

```c
#define MAX(x,y) (x)>(y) ? (x) : (y);

int maxProfit(int* prices, int pricesSize){
    if(pricesSize <= 0 ){
        return 0;
    }
    int ** dp = (int**)malloc(sizeof(int*)*pricesSize);
    for(int i = 0; i < pricesSize ; i++){
        dp[i] = (int*)malloc(sizeof(int)*2);
    }
    // 0 无持有 1 持有
    for(int  i = 0 ; i < pricesSize; i++){
        if(i-1 < 0){
            dp[i][0] = 0;
            dp[i][1] = -prices[i];
            continue;
        }
        dp[i][0] = MAX(dp[i-1][0], dp[i-1][1] + prices[i]);
        dp[i][1] = MAX(dp[i-1][1], - prices[i]);
    }
    return dp[pricesSize-1][0];
}
```