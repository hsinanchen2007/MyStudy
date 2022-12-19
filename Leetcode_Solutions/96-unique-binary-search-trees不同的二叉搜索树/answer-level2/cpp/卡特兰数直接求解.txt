### 解题思路
本题和上题类似，但是只需要给出二叉树的数目，根据卡特兰数的定义可以直接求解。
### 代码

```cpp
class Solution 
{
public:
    int numTrees(int n) 
    {

        int dp[n + 1] = {0};

        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2; i < n + 1; i++)
        {
            for(int j = 1; j < i + 1; j++) 
            {
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        
        return dp[n];
    }
};
```