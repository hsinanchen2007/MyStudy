排序后遍历，判断区间结束端点是否大于后继区间起始端点，用以合并区间
```
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()<2) return intervals;
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ret;
        int i = 0;
        while(i<intervals.size()){
            int begin = intervals[i][0]; 
            int end = intervals[i][1];
            while(i<intervals.size()-1 && end>=intervals[i+1][0]){
                i++;
                if(end<intervals[i][1]) end = intervals[i][1];
            }
            ret.push_back({begin,end});
            i++;
        }
        return ret;
    }
};
```
