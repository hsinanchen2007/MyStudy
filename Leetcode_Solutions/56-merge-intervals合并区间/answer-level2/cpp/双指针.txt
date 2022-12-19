### 解题思路
先排序，使用双指针

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty() || intervals.size() == 1) return intervals;
        vector<vector<int>> rt;
        sort(intervals.begin(), intervals.end());
        int i = 0, j = 1;
        while(j < intervals.size()){
            if(intervals[i][1] < intervals[j][0]){
                rt.push_back(intervals[i]);
                i = j;
            }
            else if(intervals[i][1] < intervals[j][1]){
                intervals[i][1] = intervals[j][1];
            }
            j++;
        }
        rt.push_back(intervals[i]);
        return rt;
    }
};
```