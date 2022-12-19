### 解题思路
主要是如何去重

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        helper(nums, 0, res);
        return res;
    }

    void helper(vector<int>& nums, int index, vector<vector<int> >& res) {
        if (index == nums.size()) {
            res.push_back(nums);
        }
        for(int i = index; i < nums.size(); ++i) {
            if (i != index && nums[i] == nums[index]) {
                continue;
            }
            int j = i-1;
            for( ; j >= index; --j) {
                if (nums[i] == nums[j]){
                    break;
                }
            }
            if (j !=  index -1) {
                continue;
            }
            swap(nums[index], nums[i]);
            helper(nums, index+1, res);
            swap(nums[index], nums[i]);
        }
    }
};
```