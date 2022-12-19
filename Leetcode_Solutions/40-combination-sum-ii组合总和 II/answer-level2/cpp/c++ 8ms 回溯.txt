### 解题思路
如何去重？

先对candidates数组进行排序，构造next_pos数组记录下一个不同的候选值的位置
递归时，当选择了当前值，则不用忽略candidates数组中的相同元素
当没有选择当前值，则后续与当前值相等的候选值值也要一并跳过（利用next_pos数组）

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> result;
    vector<int> sum;
    vector<int> next_pos;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> arr(target);
        sort(candidates.begin(), candidates.end());

        sum.resize(candidates.size(), 0);
        next_pos.resize(candidates.size(), candidates.size());
        sum[candidates.size()-1] = candidates[candidates.size()-1];
        next_pos[candidates.size()-1] = candidates.size();
        for (int i = candidates.size()-2; i >= 0; --i) {
            sum[i] = sum[i+1] + candidates[i];
            if (candidates[i] == candidates[i+1]) {
                next_pos[i] = next_pos[i+1];
            } else {
                next_pos[i] = i+1;
            }
        }

        combinationSum2(candidates, 0, arr, 0, target);
        return result;
    }

    void combinationSum2(vector<int>& c, int c_pos, vector<int>& a, int a_pos, int target) {
        if (!target) {
            vector tmp(a.begin(), a.begin() + a_pos);
            result.emplace_back(std::move(tmp));
            return;
        }
        if (c_pos >= c.size() || target < 0) return;
        if (sum[c_pos] < target) return;
        a[a_pos] = c[c_pos];
        combinationSum2(c, c_pos + 1, a, a_pos + 1, target-c[c_pos]); // 不跳过相同值
        combinationSum2(c, next_pos[c_pos], a, a_pos, target); // 传入next_pos[c_pos]跳过相同值
    }
};
```