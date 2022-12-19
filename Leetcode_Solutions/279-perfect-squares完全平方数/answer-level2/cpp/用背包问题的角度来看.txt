转化为了 正好装满的完全背包问题，目标是让价值尽可能的小。
其中 货物的价值 全都是 1， 货物的大小就是 平方数的数值。
背包的空间就是目标数字n的大小。
```
class Solution {
public:
    int numSquares(int n) {
        int tmp = sqrt(n);
        //int dp[10000] = {0};
        int * dp = (int*)calloc(n+1, sizeof(int));
        int INF = 0x7fffffff ;
        for(int i = 0; i<=n;i++)
            dp[i] = INF;
        dp[0] = 0;
        int w,v;
        for(int i = 1;i<=tmp;i++)
        {
            w = i*i;
            v = 1;
            for(int j = w;j<=n;j++)
            {
                if(dp[j-w]!=INF)
                    dp[j] = min(dp[j], dp[j-w]+v);
            }
            
        }        
        return dp[n];
    }
};
```
执行用时 :168 ms, 在所有 C++ 提交中击败了44.74%的用户
内存消耗 :11.3 MB, 在所有 C++ 提交中击败了41.94%的用户
