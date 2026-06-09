### 解题思路
sort 用 反向迭代器，来逆序
### 代码

```cpp
class Solution {
public:
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        long long res=0,sum=0;
        const int mod=1e9+7;
        multiset<int>maintain;
        vector<pair<int,int > >vpar;        
        for(int i=0;i<n;++i)
            vpar.push_back({efficiency[i],speed[i]});
        sort(vpar.rbegin(),vpar.rend());

        for(auto item:vpar){
            maintain.insert(item.second);
            sum+=item.second;
            if(maintain.size()==k+1){
                sum-=*maintain.begin();
                maintain.erase(maintain.begin());
            }
            res=max(res,sum*item.first);
        }
        return res%mod;
    }
};
```