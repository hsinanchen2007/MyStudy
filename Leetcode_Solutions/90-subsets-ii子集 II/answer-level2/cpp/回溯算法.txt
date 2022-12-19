### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
    vector<vector<int>> res;
    void dfs(vector<int>& nums, int start, vector<int>& path) {
        res.push_back(path);

        for(int i = start; i < nums.size(); i++) {
            //和上个数字相等就跳过
            if(i > start && nums[i] == nums[i-1]) {
                continue;
            }
            path.push_back(nums[i]);
            dfs(nums, i + 1, path);
            path.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        res.clear();
        if(nums.size() == 0) {
            return res;
        }
        sort(nums.begin(), nums.end());
        vector<int> path;
        dfs(nums, 0, path);
        return res;
    }
};
```