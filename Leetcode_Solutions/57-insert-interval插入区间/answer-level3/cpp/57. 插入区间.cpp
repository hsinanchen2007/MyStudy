```
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size() == 0)
            return {newInterval};
        vector<vector<int>> res;
        for(int i = 0; i < intervals.size(); i++){
            if(intervals[i][1] < newInterval[0] || intervals[i][0] > newInterval[1]){
                res.push_back(intervals[i]);
                continue;
            }
            if(intervals[i][1] > newInterval[1])
                newInterval[1] = intervals[i][1];
            if(intervals[i][0] < newInterval[0])
                newInterval[0] = intervals[i][0];
           
        }
        res.push_back(newInterval);
        sort(res.begin(),res.end());
        return res;
    }
};
```
