### 代码

```cpp
class Solution {
public:
//f(n) = min(f(n-1),f(n-4),f(n-9),...)+1
    int numSquares(int n) {
        //f(n) = dp[n]
        vector<int> dp(n+1,0);
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2;i<n+1;++i)
        {
            //dp[i]
            int tmp = INT_MAX;
            for(int j=1;j*j<=i;++j)
            {
                //tmp = min(dp[i-j*j],tmp); //用min会很慢
                tmp = dp[i-j*j]<tmp?dp[i-j*j]:tmp;
            }
            
            dp[i]=tmp+1;
        }
        return dp[n];
    }
};


```