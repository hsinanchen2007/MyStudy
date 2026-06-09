### 解题思路
dp[i]里面存放的是当n=i时的最大值；
那么当i= i+1之后，
dp[i]应该等于多少呢？
中间的循环解决的问题就是要求整数为n时的最大值，通过循环实现
不断比较的值是
dp[i-j]*j,j*(i-j)和此时的dp[i]
当j =1时，相当于这个整数被分为n-1，1,计算此时的最大值为dp[i]
当j=2时，要么是将整数分为n-2,2;或者dp[i-2]*2,即在原来当n=i-2的最大值上✖2；其最大值则为新的dp[i]
当然需要更新到j=i-2,此时将所有可能的加数遍历结束，得到的即是最大值

### 代码

```cpp
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);
        dp[1]=1;
        for(int i = 2;i<=n;i++)
        {
            for(int j =1;j<=i-1;j++)
            {
                int m =(j*dp[i-j]>j*(i-j))?j*dp[i-j]:j*(i-j);
                dp[i]=(m>dp[i])?m:dp[i];
            }
        }
        return dp[n];

    }
};
```