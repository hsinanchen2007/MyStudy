对于0，要单独处理。
```
int numDecodings(char * s){
	
	if(s[0] == '0')
	{
		return 0;
	}
	
    int* dp = (int*)malloc(3 * sizeof(int));
	int i, ret;
	
	dp[0] = 1;
	dp[1] = 1;
	
 
	for(i = 1; s[i] != '\0'; i++)
	{
		if(s[i] == '0')
		{
			if(s[i - 1] == '1' || s[i - 1] == '2')
			{
				dp[(i + 1)%3] = dp[(i - 1)%3];
			}
			else
			{
				return 0;
			}
		}
		else if(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))
		{
			dp[(i + 1)%3] = dp[i%3] + dp[(i - 1)%3];
		}
		else
		{
			dp[(i + 1)%3] = dp[i%3];
		}
		
	}
	
	ret = dp[i%3];
	
	free(dp);
	
	dp = NULL;
	
	return ret;
} 
```
