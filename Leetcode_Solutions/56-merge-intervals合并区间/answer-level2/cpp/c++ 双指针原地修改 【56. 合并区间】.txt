### 解题思路
1. 按照区间左侧，从小到大排序
2. 初始pos=0， 迭代i <-- 1 ~n; 
    2.1 如果intervals[pos][1] >= intervals[i][0]，合并
    2.2 如果intervals[pos][1] < intervals[i][0],将当前i复制到pos的下一个位置。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (!intervals.size()) return {};
        sort(intervals.begin(), intervals.end(), less<vector<int>>());
        int pos = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[pos][1] >= intervals[i][0]) {
                intervals[pos][1] = max(intervals[pos][1], intervals[i][1]);
            } else {
                intervals[++pos] = intervals[i];
            }
        }
        intervals.resize(pos+1);
        return intervals;
    }
};
```