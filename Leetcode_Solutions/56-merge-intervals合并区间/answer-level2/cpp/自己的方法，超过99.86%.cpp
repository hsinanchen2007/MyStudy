`inside`表示当前在多少个区间内。

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        map<int, int> m;
        for (auto &interval : intervals) {
            m[interval[0]]++;
            m[interval[1]]--;
        }
        vector<vector<int>> result;
        int begin = 0;
        int inside = 0;
        for (auto &p : m) {
            if (p.second == 0) {
                if (inside == 0)
                    result.push_back({p.first, p.first});
                continue;
            }
            int new_inside = inside + p.second;
            assert(new_inside >= 0);
            if (inside == 0) {
                begin = p.first;
            } else if (new_inside == 0) {
                result.push_back({begin, p.first});
            }
            inside = new_inside;
        }
        return result;
    }
};
```
