	  public int maxProfit(int[] prices) {
		  if(prices.length<2) {
			  return 0;
		  }
		  int l = prices.length;
		  /*
		   * 这里定义二维数组的意义是  :
		   * dp[i][0]:代表手上没有股票
		   * dp[i][1]:代表手上有股票
		   */
		  int [][] dp = new int[l][2];
		  dp[0][0]=0;//代表不持有股票
		  dp[0][1]=-prices[0];//代表持有股票
		  for(int i=1;i<l;i++) {
			  dp[i][0]=Math.max(dp[i-1][0], dp[i-1][1]+prices[i]);
			  dp[i][1]=Math.max(dp[i-1][1],-prices[i]);
		  }
		  /**
		   * 最大值就是在最后一个股票的情况下不持有股票 收益最大
		   */
		  return dp[l-1][0];
	    }