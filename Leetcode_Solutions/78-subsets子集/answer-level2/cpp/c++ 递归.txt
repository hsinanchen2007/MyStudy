### 解题思路
对nums数组的每个节点有取和不取两种选择， 对两种选择分别做递归处理

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> tmp(nums.size(), 0);
        subsets(nums, tmp, 0, 0);
        return result;
    }

    void subsets(vector<int>& nums, vector<int>& tmp, int pos, int t_pos) {
        if (pos >= nums.size()) {
            result.emplace_back(vector<int>(tmp.begin(), tmp.begin()+t_pos));
            return;
        }
        tmp[t_pos] = nums[pos];
        subsets(nums, tmp, pos + 1, t_pos+1);  // 取nums[pos]
        subsets(nums, tmp, pos + 1, t_pos);    // 不取nums[pos]
    }
};
```