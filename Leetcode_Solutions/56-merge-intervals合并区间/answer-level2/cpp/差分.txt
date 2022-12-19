用差分标记线段，不过这题的线段是闭区间，所以差分的右边就应该设置为线段的右端点，而不是线段右端点加一。
因为考虑到线段的下标可能是负数，所以用map记录差分数组，这样也可以加快速度。
```cpp
const int INF=0x3f3f3f3f;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int> >& inter=intervals;
        int sz=inter.size();
        if (sz==0) {
            return {};
        }
        map<int,int> mp;
        vector<vector<int> > ans;
        for (auto i:intervals) {
            mp[min(i[0],i[1])]++;
            mp[max(i[0],i[1])]--;
        }
        int beg=INF;
        int pre=0;
        int cur=0;
        for (auto p:mp) {
            beg=min(beg,p.first);
            cur=pre+p.second;
            if (!cur) {
                ans.push_back({beg,p.first});
                beg=INF;
            }
            pre=cur;
        }
        return ans;
    }
};
```