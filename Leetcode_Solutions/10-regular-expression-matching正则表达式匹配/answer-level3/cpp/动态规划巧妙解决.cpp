### 解题思路
对于用动态规划解决，我们首先想到的肯定是得建立一张表格来记录比较得过程，在这里我建立了一个二维数组dp[i][j]用来记录匹配得的过程，为了便于边界的计算我多初始化了一行一列。
解决这种问题的难点在于我们要考虑到每一种情况，这也是很多人解决这类问题遇到的难点，在这里可以考虑以下几种情况：
1.当p[i-1]='.'时dp[i][j]=dp[i-1][j-1],若是之前的匹配成功了那么这一位也可以匹配成功（i-1因为dp多初始化了）。
2.当p[i-1]=s[j-1] 时 dp[i][j]=dp[i-1][j-1];
2.当p[i-1]='*' 时 表示可以匹配0-n个p[i-2],这种情况是最不好分析的也是解决本题的关键
  (1)当匹配1个时，dp[i][j]=dp[i-1][j]
  (2)当匹配多个时，dp[i][j]=dp[i][j-1]  //这一点思路可能会转不过弯来，多想想
       (1)(2)可以合并dp[i][j]=dp[i-1][j]||dp[i][j-1]
  (3)当匹配0个时，dp[i][j]=dp[i-2][j]||dp[i][j](注意边界i>1)
3.以上情况都不满足时，dp[i][j]=false;
  可以对照下面的代码进行理解。
下图给出一个详细实例：
![image.png](https://pic.leetcode-cn.com/6fd15489577863890c2f7fc4d1fcdd9a91832d1ccd3b6222a55551a2d38560f1-image.png)

### 代码

```cpp
class Solution {
public:
	bool isMatch(string s, string p) {
		if (s.empty() && p.empty())
		{
			return true;
		}
		if (p.empty())
		{
			return false;
		}
		vector<vector<bool>>dp(p.length() + 1, vector<bool>(s.length() + 1, false));
		dp[0][0] = true;
		for (int i = 1; i <= p.length(); i++)
		{
			for (int j = 0; j <= s.length(); j++)
			{
				if (j == 0) //这个判断用来，判断s为空，p不为空的情况
				{
					if (p[i - 1] == '*')
					{
						dp[i][j] = dp[i - 2][j];
					}
					else
					{
						dp[i][j] = false;
					}
				}
				else   //这个判断用来判断s,p都不为空的情况
				{
					if (p[i - 1] == '*')
					{  
						if (i > 1)
						{
							if (p[i - 2] == s[j - 1] || p[i - 2] == '.')
							{
								dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
							}
							dp[i][j] = dp[i][j] || dp[i-2][j];
						}
					}
					else if (p[i - 1] == '.')
					{
						dp[i][j] = dp[i - 1][j - 1];
					}
					else
					{
						if (p[i - 1] == s[j- 1])
						{
							dp[i][j] = dp[i - 1][j - 1];
						}
						else
						{
							dp[i][j] = false;
						}
					}
				}
			}
		}
		return dp[p.length()][s.length()];
	}
};
```