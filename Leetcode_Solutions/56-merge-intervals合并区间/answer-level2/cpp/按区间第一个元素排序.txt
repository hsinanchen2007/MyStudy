### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty() || intervals[0].empty()) {
            return vector<vector<int>>();
        }
        sort(intervals.begin(), intervals.end(),[](vector<int>& a, vector<int>&b){
            return a[0] < b[0];
        });

        int start = intervals[0][0], end = intervals[0][1];
        vector<vector<int>> res;
        for (int i = 1, sz = intervals.size(); i < sz; ++i) {
            if (intervals[i][0] > end) {
                res.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            } else {
                start = min(start, intervals[i][0]);
                end = max(end, intervals[i][1]);
            }
        }
        res.push_back(vector<int>{start, end});

        return res;
    }
};
```