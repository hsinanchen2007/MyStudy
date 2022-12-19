### 解题思路

1. 站在第n-1阶楼梯时，达到第n阶楼梯有1种方法
2. 站在第n-2阶楼梯时，达到第n阶楼梯有2种方法
3. 而`f(n)=f(n-1)+f(n-2)`
4. 即`return climbStairs(n-1)+climbStairs(n-2);`
5. 将函数递归，转化为数组迭代

### 代码
```
class Solution 
{
public:
    int climbStairs(int n) 
    {
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;

        vector<int>dp(n,0);
        dp[0]=1;
        dp[1]=2;
        for(int i=2;i<n;++i)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n-1];
    }
};
```