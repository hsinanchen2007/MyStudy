考虑每收到一个件，就去安排他的派件位置，从而每次收件都在当前最靠前的可用位置。
第一个件有2n-1个派发位置，第二个有2n-3个...第n个件有1个，这样派件顺序有(2n-1)!!种，再乘以收件顺序n!

```
class Solution {
public:
    const int mod=1000000007;
    int countOrders(int n) {
        long long ans=1;
        for(int i=2;i<=n;++i){
            ans*=i;
            ans%=mod;
            ans*=(i*2-1);
            ans%=mod;
        }
        return ans;
    }
};
```

0ms.