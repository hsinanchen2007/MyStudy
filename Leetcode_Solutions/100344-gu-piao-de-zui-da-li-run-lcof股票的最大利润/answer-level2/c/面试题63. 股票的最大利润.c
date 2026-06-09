dp[i][k][0]表示第i天最大可交易数量为k时未持有股票的状态；
dp[i][k][1]表示第i天最大可交易数量为k时持有股票的状态;
状态转移方程：
dp[i][k][0] = max(dp[i][k][0], dp[i - 1][k][1] - prices[i]);
dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] + prices[i]);
注意：因为第i天持有了股票且最大可交易次数为k，因此第i - 1天最大可交易次数为k - 1次。

        int max(int a, int b)
        {
            if (a > b) {
                return a;
            }
            return b;
        }
        
        int maxProfit(int* prices, int pricesSize)
        {
            if (pricesSize == 0) {
                return 0;    //易出错
            }
            const int MAX = 200000;
            const int TIMES = 1;
            const int STATUS = 2;
            int dp[MAX][TIMES + 1][STATUS];
            int i;
            int j;
            int k;
            for (i = 0; i < MAX; i++) {
                for (k = TIMES; k > 0; k--) {
                    dp[i][k][0] = 0;
                    dp[i][k][1] = 0;
                }
            }
        
            for (i = 0; i < pricesSize; i++) {
                for (k = TIMES; k > 0; k--) {
                    if (i == 0) {
                        dp[i][k][0] = 0;
                        dp[i][k][1] = -prices[i];   //易出错
                        continue;
                    }
                    dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
                    dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][1] - prices[i]);  //k - 1易出错
                }
            }
        
            return dp[pricesSize - 1][TIMES][0];
        }