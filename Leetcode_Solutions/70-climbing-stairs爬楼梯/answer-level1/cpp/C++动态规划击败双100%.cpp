### 解题思路


![6.png](https://pic.leetcode-cn.com/9952ee8ce27e2e3561b9d57628d776eb6575118ac1e238aa8c5f94062f40d94d-6.png)

典型的动态规划问题，思考状态转移方程，也就是当前状态是如何由上一个状态转移而来的
可以很容易想到它的状态转移方程
dp[i]=dp[i-1]+dp[i-2]  i>=2
dp[i]=2       i==1
dp[i]=1       i==0
### 代码

```cpp
class Solution {
public:
    int climbStairs(int n) 
    {
        //dp[i]=dp[i-1]+dp[i-2] i>=2
        //dp[i]=2       i==1
        //dp[i]=1       i==0

        vector<int>dp;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            dp.push_back(1);
            else if(i==1)
            dp.push_back(2);
            else if(i>=2)
            {
            int temp=dp[i-1]+dp[i-2];
            dp.push_back(temp);
            }
        }
        return dp.back();

    }
};
```