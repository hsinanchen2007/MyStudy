```
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans{intervals[0]};
        int n = intervals.size();
        for(int i = 0; i < n; i ++){
            if(ans.back()[1] >= intervals[i][0]){
                ans.back()[1] = max(intervals[i][1], ans.back()[1]);
                continue;
            }
            else{
                ans.push_back(intervals[i]);
                continue;
            }
        }
        return ans;
        
    }
};
```
