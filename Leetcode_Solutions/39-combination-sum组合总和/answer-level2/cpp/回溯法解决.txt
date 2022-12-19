### 解题思路
难点在于如何避免重复的情况。先选一个元素和后选一个元素没有区别，所以从遍历来说就是把包含一个元素的所有解都列出来再继续遍历下一个。

### 代码

```cpp
class Solution {
public:
    void combinationSum_core(int start, int & sum, int & target, vector<int> & candidates, vector<int> & _ans, vector<vector<int>> & re) {
        if (sum == target) {
            re.push_back(_ans);
            return;
        }
        if (sum > target) return;
        for (int i=start; i<candidates.size(); i++) {
            _ans.push_back(candidates[i]);
            sum += candidates[i];
            combinationSum_core(i, sum, target, candidates, _ans, re);
            _ans.pop_back();
            sum -= candidates[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> re;
        if (candidates.size()==0 || target <= 0) return re;
        vector<int> _ans;
        int sum = 0;
        combinationSum_core(0, sum, target, candidates, _ans, re);
        return re;
    }
};
```