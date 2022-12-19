### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int cuttingRope(int n) {
            int dp[60];
            dp[2]=1;
            dp[3]=2;
            dp[4]=4;
            //dp[5]=6;
            for(int i=5;i<=58;i++)
            {
                dp[i]=max(3*dp[i-3],3*(i-3));
            }
            return dp[n];
    }
};
```