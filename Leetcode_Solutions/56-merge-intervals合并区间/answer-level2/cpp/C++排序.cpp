```
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if(intervals.size() == 0)
            return result;
        if(intervals.size() == 1)
            return intervals;
        sort(intervals.begin(), intervals.end());
        for(int i = 0; i < intervals.size() - 1; i++)
        {
            if(intervals[i+1][0] <= intervals[i][1])
            {
                intervals[i+1][0] = intervals[i][0];
                intervals[i+1][1] = max(intervals[i][1], intervals[i+1][1]);
            }
            else
                result.push_back(intervals[i]);
        }
        result.push_back(intervals.back());
        return result;
    }
};
```
