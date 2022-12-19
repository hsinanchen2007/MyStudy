```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<=1)return 0;
        vector<int> f(n,0);
        int b=0;

        int pmin=prices[0];
        int pmax=prices[n-1];

        for(int i=1;i<n;++i)
        {
            f[i]=max(f[i-1],prices[i]-pmin);
            pmin=min(pmin,prices[i]);
        }

        int res=f[n-1];
        for(int i=n-2;i>=0;--i)
        {
            b=max(b,pmax-prices[i]);
            res=max(res,f[i]+b);
            pmax=max(pmax,prices[i]);
        }
        
        return res;
    }
};
```
