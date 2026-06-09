四种线的代码大体相同。CV大法
```
class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
		
		m = M.size();
		
		if(m <= 0)
		{
			return 0;
		}
		
		n = M[0].size();
		
		vatrticalLine(M);
		horizon(M);
		diagonalLine(M);
		backDiagonalLine(M);
		
		return ret;
    }

private:
	int ret = 0;
	int m = 0;
	int n = 0;
	
	void vatrticalLine(vector<vector<int>>& M)
	{
		vector<int>dp(m + 1, 0);
		
		for(int j = 0; j < n; j++)
		{
			for(int i = 1; i < m + 1; i++) //i预留了一个0，作为初始值
			{
				if(M[i - 1][j] == 1)
				{
					dp[i] = dp[i - 1] + 1;
				}
				else
				{
					dp[i] = 0;
				}
				
				ret = max(ret, dp[i]);
			}
		}
	}
	
	
	void horizon(vector<vector<int>>& M)
	{
		vector<int>dp(n + 1, 0);
		
		for(int i = 0; i < m; i++)
		{
			for(int j = 1; j < n + 1; j++) //i预留了一个0，作为初始值
			{
				if(M[i][j - 1] == 1)
				{
					dp[j] = dp[j - 1] + 1;
				}
				else
				{
					dp[j] = 0;
				}
				
				ret = max(ret, dp[j]);
			}
		}
	}
	
	void diagonalLine(vector<vector<int>>& M)
	{
		vector<int>dp(n + 1, 0);
		
		for(int i = 0; i < m; i++)
		{
			for(int j = n; j > 0; j--) //i预留了一个0，作为初始值
			{
				if(M[i][j - 1] == 1)
				{
					dp[j] = dp[j - 1] + 1;
				}
				else
				{
					dp[j] = 0;
				}
				
				ret = max(ret, dp[j]);
			}
		}
	}
	
	
	void backDiagonalLine(vector<vector<int>>& M)
	{
		vector<int>dp(n + 1, 0);
		
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++) //i预留了一个0，作为初始值
			{
				if(M[i][j] == 1)
				{
					dp[j] = dp[j + 1] + 1;
				}
				else
				{
					dp[j] = 0;
				}
				
				ret = max(ret, dp[j]);
			}
		}
	}
	
};
```
