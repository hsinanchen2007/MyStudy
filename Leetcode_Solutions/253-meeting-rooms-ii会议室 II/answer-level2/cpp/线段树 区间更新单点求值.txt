```
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> m;
        for(auto& v: intervals) m[v[0]]++, m[v[1]]--;
        int ans = 0, res = 0;
        for(auto& it: m) {
            ans += it.second;
            res = max(res, ans);
        }
        return res;
    }
};
```
