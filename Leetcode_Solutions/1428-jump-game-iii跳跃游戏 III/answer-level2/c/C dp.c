在dp[i][j] : 0，未知， 1 可达， 2不可达， -1正在求解
        j  : 0 向左， 1 向右
```
int canReachCore(int* arr, int arrSize, int dp[][2], int cur); 
bool canReach(int* arr, int arrSize, int start){
	
	int dp[arrSize][2];
	
	memset(dp, 0, arrSize * 2 * sizeof(int));
	
	dp[start][0] = -1;
	dp[start][1] = -1;
	
	dp[start][0] = canReachCore(arr, arrSize, dp, start - arr[start]);
	dp[start][1] = canReachCore(arr, arrSize, dp, start + arr[start]);
	
	return (dp[start][0] == 1 || dp[start][1] == 1);

}

int canReachCore(int* arr, int arrSize, int dp[][2], int cur)
{
	if(cur < 0 || cur >= arrSize)
	{
		return 2;
	}
	
	if(arr[cur] == 0)
	{
		return 1;
	}

	if(dp[cur][0] == 0)
	{
		dp[cur][0] = -1;
		dp[cur][0] = canReachCore(arr, arrSize, dp, cur - arr[cur]);
	}
	
	if(dp[cur][1] == 0)
	{
		dp[cur][1] = -1;
		dp[cur][1] = canReachCore(arr, arrSize, dp, cur + arr[cur]);
	}
	
	if(dp[cur][0] == 1 || dp[cur][1] == 1)
	{
		return 1;
	}
	
	return 2;
}
```