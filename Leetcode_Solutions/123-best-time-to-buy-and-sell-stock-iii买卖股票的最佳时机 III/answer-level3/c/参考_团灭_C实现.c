#define INVALID 0xFFFFFFFF
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxProfit(int* prices, int pricesSize){
    if (pricesSize < 2)
        return 0;
        
    //#1定义动态规划数组的含义  dp 三维数组
    //dp[天数][交易次数][是否持有股票]
    int dp[pricesSize][3][2];
    memset(dp, 0, sizeof(int) * pricesSize * 3 * 2);


    //#2定义basecase
    //交易次数从1开始，等于0时说明不允许交易，利润0
    dp[0][0][0] = 0;
    //交易次数0时，不允许交易，所以不存在持有的状态
    dp[0][0][1] = INVALID;    
    //所谓一笔交易指的是，有买有卖，所以1笔交易持有的情况下利润是负的
    dp[0][1][0] = 0;
    dp[0][1][1] = -prices[0];
    //2笔交易指的是，有买有卖
    dp[0][2][0] = 0;
    dp[0][2][1] = -prices[0]; 

    //#3找出状态转移方程
    for (int i = 1; i < pricesSize; i++) {
        for (int k = 2; k > 0; k--) {
            //今天没有持有，把昨天持有的卖掉，要么昨天没有持有今天不进行交易
            dp[i][k][0] = MAX(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
            //今天持有，昨天没有持有今天买入，昨天持有今天继续观察不做交易
            dp[i][k][1] = MAX(dp[i - 1][k][1], dp[i - 1][k -1][0] - prices[i]);
        }
    }

    //返回值肯定是处于最后一天的卖出状态
    return dp[pricesSize - 1][2][0];
}

