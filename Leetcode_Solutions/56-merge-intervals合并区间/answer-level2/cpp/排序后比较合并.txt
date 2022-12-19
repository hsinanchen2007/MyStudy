### 解题思路
先排序，这样可以保证A[i][0] <= A[j][0] if(i < j)
随后如果出现A[i][1] >= A[j][0] if(i < j) 说明可以合并
此外，使用 hash 减少循环次数

### 代码

```cpp
bool cmp(vector<int> a, vector<int> b){
    return a[0] < b[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<bool> table(intervals.size(), false);
        vector<vector<int>> res; 
        for(int i = 0; i < table.size(); ++i){
            vector<int> tmp = {intervals[i][0], intervals[i][1]};
            if(table[i]) continue;
            for(int j = i+1; j < table.size(); ++j){
                if(table[j]) continue;
                if(tmp[1] >= intervals[j][0]){
                    table[i] = true; table[j] = true;
                    tmp[0] = intervals[i][0];
                    tmp[1] = max(intervals[j][1], tmp[1]);
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};
```

### 结果
执行用时 : 160 ms , 在所有 C++ 提交中击败了 9.30% 的用户 
内存消耗 : 25.1 MB , 在所有 C++ 提交中击败了 15.74% 的用户