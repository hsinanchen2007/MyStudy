### 解题思路

快速幂

### 代码

```cpp

typedef long long ll;
ll qu(ll x,ll a){
    ll ret=1;
    while(a){
        if(a&1)ret*=x;
        x*=x;a>>=1;
    }
    return ret;
}
class Solution {
public:
    bool isArmstrong(int N) {
        ll tmp=10,i;
        for(i=1;tmp<=N;i++,tmp*=10);
        ll res=0,n=N;
        while(N){res+=qu(N%10,i);N/=10;}
        return res==n;
    }
};
```