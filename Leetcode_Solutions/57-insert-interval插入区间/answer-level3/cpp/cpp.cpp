### 解题思路
首先判断待插入区间是否在所有区间的左端，直接插入即可。
然后设置是否插入的标志，一旦已经插入了，后面就直接将所有的区间插入即可。循环后，如果依然没有插入，说明该区间应该是最右边的区间，所以应该放到最后。

使用交并比判断两个线段是否相交。

如果相交直接merge
不相交的时候，需要判断当前的区间和待插入的区间的左右关系，如果当前区间在待插入区间的左边，应该直接插入当前区间。如果在右边，则说明待插入区间已经找到了合适的位置，此时直接按顺序插入 两个区间即可。

代码并不复杂，可能有些corner case需要考虑

### 代码

```cpp
class Solution {
public:
    bool check(int l, int r, int nl, int nr) {
        // check Point(l, r) intersect with Point(nl, nr) or not
        return min(r, nr) >= max(l, nl);
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) return {newInterval};
        vector<vector<int>> ans;
        int nl = newInterval[0], nr = newInterval[1];
        if (nr < intervals[0][0]) {
            intervals.insert(intervals.begin(), {nl, nr});
            return intervals;
        }
        bool insert_flag = false; // whether inserted or not 
        for (int i = 0; i < intervals.size(); i ++) {
            int l = intervals[i][0], r = intervals[i][1];
            if (insert_flag) {
                ans.push_back({l, r});
                continue;
            }
            bool is_sec = check(l, r, nl, nr);
            if (is_sec) {
                //merge
                nl = min(l, nl);
                nr = max(r, nr);
            }
            else if (!is_sec && nr < l) {
                ans.push_back({nl, nr});
                ans.push_back({l, r});
                insert_flag = true;
            }
            else if (!is_sec && r < nl) 
                ans.push_back({l, r});
        }
        if (!insert_flag)
            ans.push_back({nl, nr});
        return ans;
    }
};
```