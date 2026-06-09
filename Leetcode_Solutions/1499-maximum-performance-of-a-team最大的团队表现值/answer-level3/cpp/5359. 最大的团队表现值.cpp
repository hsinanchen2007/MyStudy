### 解题思路
Multiset 存前k大的speed值然后和枚举的efficiency相乘取最大值，注意这里的取模是算完所有了对答案取模而不是中间步骤取模，这样会出错
### 代码

```cpp
class Solution {
    #define ll long long
    #define rg ll
    const ll mod=1e9+7;
    struct node
    {
        ll sp,ef;    
        bool operator <(const node& a)const
        {
            if(a.ef==ef)return sp>a.sp;
            return ef>a.ef;
        }
    }p[100005];
    multiset<ll>t;
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        for(rg i=0;i<speed.size();i++)
        {
            p[i].sp=speed[i],p[i].ef=efficiency[i];
        }
        sort(p,p+n);
        ll ans=-1,tep=0;
        for(rg i=0;i<n;i++)
        {
            t.insert(p[i].sp);
            tep+=p[i].sp;
            if(t.size()>k)tep-=*t.begin(),t.erase(t.begin());
            ans=max(ans,p[i].ef*tep);
        }
        return ans%mod;
    }
};
```