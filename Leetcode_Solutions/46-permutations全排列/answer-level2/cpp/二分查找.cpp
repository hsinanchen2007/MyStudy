### 解题思路
常规的二分查找

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<int> permutation;

    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums);
        return res;
    }

    void dfs(vector<int>& nums){
        if(permutation.size() == nums.size()) {
            res.push_back(permutation);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(find(permutation.begin(), permutation.end(), nums[i]) == permutation.end()) {  //排除重复的项目
                permutation.push_back(nums[i]);
                dfs(nums);
                permutation.pop_back();
            }
        }
        return;
    }
};
```