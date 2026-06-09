### 解题思路
思路如下图：
![捕获.PNG](https://pic.leetcode-cn.com/455a86bf87800938b6dcfecab039e106916df1f9dcdd302ff45d5a2ddedf09dd-%E6%8D%95%E8%8E%B7.PNG)




### 代码

```cpp
class Solution {
public:
	int longestValidParentheses(string s) {
		int max = 0;
		vector<int>dp(s.length(),0);
		for(int i=1;i<s.length();i++)
        {
            if(s[i]==')')
            {
                if(s[i-1]=='(')
                {
                    dp[i]=i-1>0?dp[i-2]+2:2;
                }
                else if(i-1-dp[i-1]>=0&&s[i-1-dp[i-1]]=='(')
                {
                    if(i-dp[i-1]-2>=0)
                    {
                       dp[i]=dp[i-1]+2+dp[i-dp[i-1]-2];
                    }
                    else
                    {
                        dp[i]=dp[i-1]+2;
                    } 
                }
            }
            max=max>dp[i]?max:dp[i];
        }
        return max;
	}
};
```