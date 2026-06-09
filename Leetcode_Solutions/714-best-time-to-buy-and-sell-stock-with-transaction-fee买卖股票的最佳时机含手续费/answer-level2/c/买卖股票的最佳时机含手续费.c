		int max(int a, int b)
		{
			if (a > b) {
				return a;
			} 
			return b;
		}
		int maxProfit(int* prices, int pricesSize, int fee)
		{
			const int MAX = 5000;
			const int status = 2;
			int dp[MAX][status];
			int i;
			for (i = 0; i < MAX; i++) {
				dp[i][0] = 0;
				dp[i][1] = 0;
			}
		
			dp[0][0] = 0;
			dp[0][1] = -prices[0] - fee;
			for (i = 1; i < pricesSize; i++) {
				dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
				dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i] - fee);
			}
		
			return dp[pricesSize - 1][0];
		}