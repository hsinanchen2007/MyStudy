### 解题思路
类似1079题活字印刷，使用额外表记录元素的访问，同时每轮回溯循环中，比对前后回溯的元素值，避免重复
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty()) {
            return res;
        }

        vector<int> tmp;
        vector<bool> visited(nums.size(), false);

        sort(nums.begin(), nums.end());
        tmp.reserve(nums.size());
        dfs(nums, visited, tmp, res);
        return res;
    }

    void dfs(vector<int>& nums, vector<bool>& visited, vector<int>& tmp, vector<vector<int>>& res) {
        if (tmp.size() == nums.size()) {
            res.push_back(tmp);
        }

        bool flag = false;
        int pre = 0;
        for (int i = 0, sz = nums.size(); i < sz; ++i) {
            if (flag && pre == nums[i]) {
                continue;
            }

            if (!visited[i]) {
                flag = true;
                pre = nums[i];
                visited[i] = true;
                tmp.push_back(nums[i]);
                dfs(nums, visited, tmp, res);
                tmp.pop_back();
                visited[i] = false;
            }
        }
    }
};
```