### 解题思路
该题是典型的动态规划题目，在传统的dp数组的基础上我们根据题目可以发现使用滚动dp数组可以更加节省内存的开销，通过循环的更新滚动dp数组的值即可以得到最终的结果。

### 代码

```cpp
class Solution {
public:
    int dp[3]={1,2,3};
    int climbStairs(int n) {
        if(n<=3)
            return dp[n-1];
        else
        {
            int temp=4;
            while(temp<=n)
            {
                dp[(temp-1)%3]=dp[(temp-2)%3]+dp[temp%3];
                temp++;
            }
            return dp[(n-1)%3];
        }
    }
};
```