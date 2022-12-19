### 解题思路
先排序，再合并。

### 代码

```cpp
bool compare(const vector<int> &a, const vector<int> &b) {
    return a[0] < b[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        
        vector<vector<int>> ans;
        for (auto vi : intervals) {
            if (ans.empty() || ans.back()[1] < vi[0])
                ans.push_back(vi);
            else if (vi[1] > ans.back()[1])
                ans.back()[1] = vi[1];
        }

        return ans;
    }
};
```