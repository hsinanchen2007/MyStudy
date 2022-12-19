### 解题思路
此处撰写解题思路

### 代码
设dp[i][j]为：数组A中0到i的部分和数组B中0到j的部分的最多连线次数。状态转移的开始和结束在代码中标注。
```cpp
class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
    if(A.size()==0||B.size()==0)
    return 0;
    int a_size = A.size();
	int b_size = B.size();
	int**dp = new int*[a_size];
	for (int i = 0; i < a_size; i++)
	{
		dp[i] = new int[b_size];
		for (int j = 0; j < b_size; j++)
		{
			if (i == 0)//状态转移部分的开始
			{
				if (A[i] == B[j])
					dp[i][j] = 1;
				else if (j > 0)
				{
					dp[i][j] = dp[i][j - 1];
				}
				else dp[i][j] = 0;
			}
			else
			{
				if (j == 0)
					dp[i][j] = A[i]==B[j]?1:dp[i - 1][j];
				else if (A[i] == B[j])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}//状态转移部分的结束
		}
	}
    return dp[a_size - 1][b_size - 1];
    }
};
```