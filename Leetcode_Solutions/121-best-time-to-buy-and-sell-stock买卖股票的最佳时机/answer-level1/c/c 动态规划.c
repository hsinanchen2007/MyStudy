### 解题思路
参考团灭6道股票问题
/*
dp[i][k][0] 第I天第k次交易，未持有股票
dp[i][i][1] 第I天第K次交易，持有股票

dp[i][k][0] = MAX(dp[i-1][k][0], dp[i-1][k][1] + prices[i]) // 第I-1天就未持有股票，第I-1天持有股票，第I天卖出
dp[i][k][1] = MAX(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]) //第I-1天就持有股票，第I-1天未持有股票，第I天买股票
base case :
dp[-1][k][0] = 0
dp[-1][k][1] = -32768  //第-1天不可能持有股票，所以初始化未最小值

dp[i][0][0] = 0; //没有交易
dp[i][0][1] = -32768;//没有交易过 不可能持有股票，初始化为最小值
k = 1时， dp[i][0][0] = 0;
所以状态方程变为 
dp[i][0] = MAX(dp[i-1][0], dp[i-1][1]+prices[i])
dp[i][1] = MAX(dp[i-1][1], -prices[i]);

base case :
dp[0][0] = MAX(dp[-1][0] + (-32768 + prices[0])) = 0
dp[0][1] = -prices[0];
*/

### 代码

```c
/*
dp[i][k][0] 第I天第k次交易，未持有股票
dp[i][i][1] 第I天第K次交易，持有股票

dp[i][k][0] = MAX(dp[i-1][k][0], dp[i-1][k][1] + prices[i]) // 第I-1天就未持有股票，第I-1天持有股票，第I天卖出
dp[i][k][1] = MAX(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]) //第I-1天就持有股票，第I-1天未持有股票，第I天买股票
base case :
dp[-1][k][0] = 0
dp[-1][k][1] = -32768  //第-1天不可能持有股票，所以初始化未最小值

dp[i][0][0] = 0; //没有交易
dp[i][0][1] = -32768;//没有交易过 不可能持有股票，初始化为最小值
k = 1时， dp[i][0][0] = 0;
所以状态方程变为 
dp[i][0] = MAX(dp[i-1][0], dp[i-1][1]+prices[i])
dp[i][1] = MAX(dp[i-1][1], -prices[i]);

base case :
dp[0][0] = MAX(dp[-1][0] + (-32768 + prices[0])) = 0
dp[0][1] = -prices[0];
*/
int dp[50000][2] = {0};
#define MAX(a, b) ((a) > (b) ? (a) : (b))
int maxProfit(int* prices, int pricesSize){
    int i;
    if (pricesSize ==0 || prices == NULL) {
        return 0;
    }
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    for (i = 1; i < pricesSize; i++) {
        dp[i][0] = MAX(dp[i-1][0], dp[i-1][1] + prices[i]);
        dp[i][1] = MAX(dp[i-1][1], -prices[i]);
    }
    return dp[pricesSize-1][0];
}
```