### 解题思路
从后向前迭代candidates数组， 对于数组中每个候选值有使用和不使用两种选择。

使用数组a保存执行步骤中所有的remain，a的初始值为target，
每次将剩余的值放到a数组尾部，判断a数组尾值为0时递归结束。
最后通过a[i]-a[i+1]得出每次选择的数字。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> arr(target+1);
        arr[0] = target;
        combinationSum(candidates, arr, candidates.size() - 1, 0);
        return result;
    }
    void combinationSum(vector<int>& c, vector<int>& a, int c_pos, int a_pos) {
        if (c_pos < 0 || c_pos >= c.size()) return;
        if (a[a_pos] < 0) return;
        if (!a[a_pos]) {
            vector<int> tmp;
            for (int i = 0; i < a_pos; ++i) {
                tmp.push_back(a[i] - a[i+1]);
            }
            result.emplace_back(tmp);
            return;
        }
        
        combinationSum(c, a, c_pos - 1, a_pos);
        a[a_pos + 1] = a[a_pos] - c[c_pos];
        combinationSum(c, a, c_pos, a_pos + 1);
    }
};
```