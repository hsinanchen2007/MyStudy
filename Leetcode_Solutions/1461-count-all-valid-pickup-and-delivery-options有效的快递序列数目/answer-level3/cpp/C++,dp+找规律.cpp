```
const int maxn=1e9+7;
typedef long long ll;
class Solution {
public:
    int countOrders(int n) {
        vector<ll>dp(505,0);
        if(n==1){
            return 1;
        }
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=(dp[i-1]*(2*i-1+(2*i-1)*(i-1)))%maxn;
        }
        return dp[n];
    }
};
```
