### 解题思路
之前想复杂了，其实就是一个贪心。先把右边端点小于待插入区间左边端点的区间放进去，
然后把和待插入区间有重叠的进行比较，更新区间端点，插入，最后把无重叠的放进去。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(newInterval.size()==0)return intervals;
        if(intervals.size()==0)return {newInterval};
        int i,j,n=intervals.size();
        vector<vector<int>>ans;
        for(i=0;i<n&&intervals[i][1]<newInterval[0];i++)ans.push_back(intervals[i]);
        for(j=i;j<n&&intervals[j][0]<=newInterval[1];j++){
            newInterval[0]=min(intervals[j][0],newInterval[0]);
            newInterval[1]=max(intervals[j][1],newInterval[1]);
        }
        ans.push_back(newInterval);
        for(;j<n;j++)ans.push_back(intervals[j]);
        return ans;
    }
};
```