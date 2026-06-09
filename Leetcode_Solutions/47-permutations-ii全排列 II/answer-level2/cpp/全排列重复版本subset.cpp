### 解题思路
与无重复的区别
if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == 0) {
    continue;
}
//1 used[i - 1] == 0 没用过 说明回溯到了同一层 此时接着用num[i] 则会与 同层用num[i-1] 重复
//2 used[i - 1] == 1 用过了 说明此时在num[i - 1]的下一层 相等不会重复

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() == 0) return result;
        vector<int> temp;
        vector<int> used(nums.size(), 0);
        std::sort(nums.begin(), nums.end());
        subsetHelper(result, used, temp, nums);
        return result;
    }
    void subsetHelper(vector<vector<int>>& result, vector<int>& used, vector<int>& temp, vector<int>& nums) {
         if (temp.size() == nums.size()) {
            result.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
                if (!used[i]) {
                    if(i > 0 && nums[i] == nums[i - 1] && used[i - 1] == 0) {
                        continue;
                    }
                    temp.push_back(nums[i]);
                    used[i] = 1;
                    subsetHelper(result, used, temp, nums);
                    used[i] = 0;
                    temp.pop_back();
                }
        }
        
    }
};
```