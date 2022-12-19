### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while(low < high){
            if(nums[low] + nums[high] < target)
                low++;
            else if(nums[low] + nums[high] > target)
                high--;
            else
                return {nums[low],nums[high]};
        }
        return {-1, -1};
    }
};
```