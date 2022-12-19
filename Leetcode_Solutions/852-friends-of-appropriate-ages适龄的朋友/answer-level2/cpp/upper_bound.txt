```
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        int res = 0;
        for(int i=0;i<ages.size();i++) {
            // 根据条件1求左边界
            auto l = upper_bound(ages.begin(), ages.end(), ages[i]/2+7);
            if(l==ages.end()) continue;
            // 根据条件2求右边界
            auto r = upper_bound(ages.begin(), ages.end(), ages[i]);
            // 根据条件3更新右边界
            if(ages[i]<100) r = upper_bound(l, r, 100);
            res += (r-l);
            // 去除自己
            if((*l)<=ages[i] && (r==ages.end() || (*r)>=ages[i])) res--;
        }
        return res;
    }
};
```
