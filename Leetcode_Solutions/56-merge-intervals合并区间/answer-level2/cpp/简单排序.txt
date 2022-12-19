### 解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0)
            return vector<vector<int>>{};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for(int i = 1 ; i < intervals.size() ; ++i)
        {
            if(intervals[i][0] <= intervals[i - 1][1])
            {
                intervals[i][0] = intervals[i - 1][0];
                if(intervals[i][1] <= intervals[i - 1][1])
                    intervals[i][1] = intervals[i - 1][1];
            }
            else
                ans.push_back({intervals[i - 1][0], intervals[i - 1][1]});
        }
        ans.push_back({intervals.back()[0], intervals.back()[1]});
        return ans;
    }
};
```