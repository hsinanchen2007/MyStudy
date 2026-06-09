### 解题思路
注意重复检查
重复检查只需考虑到三数相加为0的情况

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() < 3) return res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<=nums.size()-3; ++i){
            if(nums[i] > 0) return res;
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int left = i+1, right = nums.size() - 1;
            while(left < right) {
                int temp = nums[left] + nums[right];
                if(temp == -nums[i]) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    while(left < right && nums[left+1] == nums[left])  left++;
                    while(left < right && nums[right-1] == nums[right])  right--;
                    left++;
                    right--;
                }
                else if(temp > -nums[i])
                    right--;
                else
                    left++;
            }
        }
        return res;
  }
};
```