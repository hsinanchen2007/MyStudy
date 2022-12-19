### 解题思路
1. 回溯法 + 剪枝
2. 因为每一个元素都要被访问一次，需要 `visited` 数组来记录元素是否访问
3. 同一层中出现重复元素会导致重复结果，因此每一层用 `dup` 记录已访问过的元素

### 代码

```cpp
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        DFS(nums, visited);
        return res;
    }

    void DFS(vector<int>& nums, vector<bool>& visited) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        unordered_set<int> dup;
        for (int i = 0; i < nums.size(); ++i) {
            if (!visited[i] && !dup.count(nums[i])) {
                path.push_back(nums[i]);
                visited[i] = true;
                DFS(nums, visited);
                visited[i] = false;
                path.pop_back();
                dup.insert(nums[i]);
            } 
        }
    }
};
```