### 解题思路
dp[n]=1 n=1;

dp[n]=2 n=2;

dp[n]=dp[n-1]+dp[n-2] n>=3;
以下代码经优化后把空间复杂度降为常数级别
刚开始并不理解for循环下三个式子的赋值关系，直到尝试了一下:dp[n+1]=dp[n]+dp[n-1]
### 代码

```cpp
class Solution {
public:
    int climbStairs(int n) {
        int result;
        int pre = 1;
        int second =2;
        if(n<=2)
        return n;
        for(int i=3;i<=n;i++)
        {   //赋值的逻辑关系可以自己动手实操，参考dp[n]=dp[n-1]+dp[n-2]与dp[n+1]=dp[n]+dp[n-1]
            result = second + pre;
            pre=second;
            second =result;
        }
        return second;
    }
};
```