对所给区间集合进行排序，可以合并区间的条件是右边区间的下限小于等于左边区间的上限。
时间复杂度：排序O(nlogn),遍历合并O(n),总体O(nlogn)
```
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals){
        int n = intervals.size(), i = 0;
        vector<vector<int> >ans;
        sort(intervals.begin(), intervals.end());

        while(i < n){
            vector<int> tem = intervals[i];
            while(i + 1 < n && intervals[i+1][0] <= tem[1]){
                tem[1] = max(intervals[i+1][1], tem[1]);
                i++;
            } 
            ans.push_back(tem);
            i++;
        }
        
        return ans;
    }
};
```
