
从只剩一张牌拿起。
注意是交替拿。
最后dp[0]即为玩家一和玩家二的分数差
```
#define MAX(X,Y) (X > Y ? X : Y)
bool PredictTheWinner(int* nums, int numsSize){
	
	int dp[numsSize][numsSize];
	
	for(int i = 0; i < numsSize; i++)
	{
		dp[i][i] = nums[i];
	}
	
	for(int d = 1; d <= numsSize - 1; d++)
	{
		for(int i = 0; i + d < numsSize; i++)
		{
			dp[i][i + d] = MAX(-dp[i + 1][i + d] + nums[i], -dp[i][i + d - 1] + nums[i + d]);
		}
	}
	
	return dp[0][numsSize - 1] >= 0;
}
```
空间优化
用left 作为索引， right = left + d;
```
#define MAX(X,Y) (X > Y ? X : Y)
bool PredictTheWinner(int* nums, int numsSize){
	
	int dp[numsSize];
	
	for(int i = 0; i < numsSize; i++)
	{
		dp[i] = nums[i];
	}
	
	for(int d = 1; d <= numsSize - 1; d++)
	{
		for(int i = 0; i + d < numsSize; i++)
		{
			int a = -dp[i + 1] + nums[i];
			int b = -dp[i] + nums[i + d];
		    dp[i] = MAX(a,b);
		}
	}
	
	return dp[0] >= 0;
}
```

