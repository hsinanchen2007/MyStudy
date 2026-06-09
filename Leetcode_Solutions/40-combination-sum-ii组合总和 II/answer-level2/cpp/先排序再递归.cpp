### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {

private:
    vector<vector<int>> res;
    vector<int> path;
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0);
        return res;
    }
    void backtrack(vector<int>& candidates, int target, int start) {
        if (target == 0) res.push_back(path);
        else if (target < 0) return;
        else for (int i = start; i < candidates.size(); i++) {
            if(i>start && candidates[i] == candidates[i-1])
                continue;
            path.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i+1);
            path.pop_back();
        }
    }
};
```