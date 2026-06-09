### 解题思路
1、把动态数组dp长度定为n+1
2、dp取dp(上一次i循环留下来的dp)、i*dp[j-i]、i*(j-i)的最大值

看到其他解法
for (int i=1;i<=(n+1)/2;i++)
for (int j=i;j<=n;j++)
{
    dp[j]=max(dp[j],dp[j-i]*i);
}



### 代码

```cpp
class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp(n+1,0);//+1
        if(n<2) return 0;
        if(n==2) return 1;//不要写成=！！！会报错！报意想不到的错！！！！
        if(n==3) return 2;
        //n>3
        dp[0]=1;
        dp[1]=1;
        //dp[2]=1;
        //dp[3]=2;
        for (int j=4;j<=n;j++)
        for(int i=1;i<=(j+1)/2;i++)
        {
            dp[j]=max(dp[j],i*dp[j-i]);
            dp[j]=max(dp[j],i*(j-i));
        }
    return dp[n];

    }
};
```