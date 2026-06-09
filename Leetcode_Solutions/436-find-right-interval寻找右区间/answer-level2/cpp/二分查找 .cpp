### 解题思路
无需自己构造节点，用自带pair方法可降低时间复杂度和空间复杂度

![批注 2020-02-04 105633.png](https://pic.leetcode-cn.com/a05da27f382feea6e274927d9c2b733ccb75f477896f6f889a157eba8c19c683-%E6%89%B9%E6%B3%A8%202020-02-04%20105633.png)


### 代码

```cpp
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int N = intervals.size();
        vector<pair<int,int>> nodes;
        for (int i = 0; i < N; ++i) {
            nodes.push_back(make_pair(i, intervals[i][0]));
        }
        sort(nodes.begin(), nodes.end(), [](const pair<int,int>&a, const pair<int,int>& b){return  a.second<b.second;});
        vector<int> v(N, 0);
        for (int i = 0; i < N; ++i) {
            v[i] = nodes[i].second;
        }
        vector<int> res(N, -1);
        for (int i = 0; i < N; ++i) {
            auto it = lower_bound(v.begin(), v.end(), intervals[i][1]);
            if (it != v.end()) {
                res[i] = nodes[it - v.begin()].first;
            }
        }
        return res;
    }
};
```