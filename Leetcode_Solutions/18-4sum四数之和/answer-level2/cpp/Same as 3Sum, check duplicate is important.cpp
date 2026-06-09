### 解题思路
需要检查四次是否重复

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for(int i = 0; i < n-3; ++i) {
            if(i >0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j < n-2; ++j) {
                if(j > i+1 && nums[j]==nums[j-1])continue;
                int left = j+1, right = n-1;
                while(left < right) {
                    int temp = nums[i] + nums[j] + nums[left] + nums[right];
                    if(temp == target) {
                        while(left < right && nums[left+1] == nums[left])  left++;
                        while(left < right && nums[right-1] == nums[right])  right--;
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                    }
                    else if(temp > target) right--;
                    else left++;
                }
            }
        }
        return res;
    }
};
```