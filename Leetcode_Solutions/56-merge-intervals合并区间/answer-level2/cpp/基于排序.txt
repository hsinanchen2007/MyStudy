### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if(intervals.empty() || intervals.size()==1)
            return intervals;
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();++i){
            if(intervals[i][0]<=ans[ans.size()-1][1]){
                if(intervals[i][1]>ans[ans.size()-1][1])
                    ans[ans.size()-1][1]=intervals[i][1];
            }
            else
                ans.push_back(intervals[i]);
        }
        return ans;
    }
};
```