### 解题思路
看注释就可以了
### 代码

```cpp
class Solution {
public:
    int co(int i,int a){ 
        if(i==0) return a;
        return  a*co(i-1,a-1);
    }
    int countNumbersWithUniqueDigits(int n) {
        //两位数 三位数 四位数 五位数   
        //一位数  0-9 一个10种   dp[1]=10;
        //两位数 dp[2] 就是从0-9选两个数字，有10*9种选法 减去0开头非法二位数的9种 81 加上dp[1] 为91
        //三位数 dp[3]就是10*9*8 +dp[2]再减去以0开头的非法三位数9*8
        //即  dp[3]=dp[2]+10*9*8-9*8;
        
        if(n==0) return 1;
        vector<int> dp(n+2);
        dp[0]=0,dp[1]=10,dp[2]=91;
        for(int i=3;i<=n;i++)
        dp[i]=co(i-1,10)+dp[i-1]-co(i-2,9); 
        return dp[n];
        
       // return co(2,10);

    }
};
```