执行用时 :
4 ms
, 在所有 C++ 提交中击败了
89.06%
的用户
内存消耗 :
8.2 MB
, 在所有 C++ 提交中击败了
82.20%
的用户
```C++
class Solution {
public:
    int fib(int N) {
        int i;
        int dp[N+1];
        if(N==0)return 0;
        if(N==1)return 1;
        dp[0]=0;
        dp[1]=1;
        for(i=2;i<=N;i++)
            dp[i]=dp[i-1]+dp[i-2];
        return dp[N];
    }
};
```


