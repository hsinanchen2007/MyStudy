求余部分不知道该怎么用其他方法
大概200ms有点慢了
```java []
	//尝试使用动态规划解决,分为6种情况
	public int checkRecord(int n) {
		//boundary conditions
		if(n == 0) 
			return 0;
		if(n == 1)
			return 3;
		if(n == 2)
			return 8;
		
		//下面至少3个连续的评价
		//INIT
		long[][] dp = new long[n + 1][6];
		int max = 1000000007;
		int index = 3;
		
		dp[2][0] = 1;//含有A，且以L结尾
		dp[2][1] = 0;//含有A，且以LL结尾
		dp[2][2] = 3;//含有A的其他情况

		dp[2][3] = 1;//不含有A，且以L结尾
		dp[2][4] = 1;//不含有A，且以LL结尾
		dp[2][5] = 2;//不含有A的其他情况
		
		
		while(index <= n) {
			dp[index][0] = dp[index-1][2]%max;
			dp[index][1] = dp[index-1][0]%max;
			dp[index][2] = (dp[index-1][0]+dp[index-1][1]+dp[index-1][2]+dp[index-1][3]+dp[index-1][4]+dp[index-1][5])%max;
			
			dp[index][3] = dp[index-1][5]%max;
			dp[index][4] = dp[index-1][3]%max;
			dp[index][5] = (dp[index-1][3]+dp[index-1][4]+dp[index-1][5])%max;
			
			index++;
		}
		
		return (int)((dp[n][0]+dp[n][1]+dp[n][2]+dp[n][3]+dp[n][4]+dp[n][5])%max);
	}
```
