![QQ图片20190925155356.png](https://pic.leetcode-cn.com/caf558ec7a608ec821a495067601ac9fda9a14b79069c0f896d08fe65a1d668d-QQ%E5%9B%BE%E7%89%8720190925155356.png)


```
class Solution {
public:

    static bool cmp(const pair<int,int>& a,const pair<int,int>& b)
    {
        return a.first<b.first;
    }

    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size();
        int n2=n/2;
        vector<pair<int,int>> cha(n);
        for(int i=0;i<n;++i)
        {
            cha[i]=make_pair(costs[i][1]-costs[i][0],i);
        }

        stable_sort(cha.begin(),cha.end(),cmp);

        int res=0;
        for(int i=0;i<n2;++i)
        {
            res+=costs[cha[i].second][1];
        }
        for(int i=n2;i<n;++i)
        {
            res+=costs[cha[i].second][0];
        }
        return res;
    }
};
```
