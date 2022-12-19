### 解题思路

不要在原vector上erase， 会导致大量元素重复拷贝。新建一个vector来拷贝，效率反而更高
![leetcode.jpg](https://pic.leetcode-cn.com/964e6f53373a4e642a07dc6f6420debdca3b240dd5f1660d2537dd7f4e8812a6-leetcode.jpg)

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.empty()) return res;

        auto cmp = [](vector<int> &a, vector<int> &b) {return a[0] < b[0];};
        sort(intervals.begin(), intervals.end(), cmp);

        res.emplace_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++) {
            int bk = res.size() - 1;
            if(res[bk][1] >= intervals[i][0]) {
                if(res[bk][1] < intervals[i][1]) {
                    res[bk][1] = intervals[i][1];
                } 
            } else {
                res.emplace_back(intervals[i]);
            }
        }

        return res; 
    }
};
```