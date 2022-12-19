### 解题思路

已知递增数组，我们通过前后2个指针，取先后的数之和，如果大了，那么需要后指针往前调整，如果小了，则需要左指针往后调整。


### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int total = nums[left] + nums[right];
            if (total == target) {
                // 匹配上了
                result.push_back(nums[left]);
                result.push_back(nums[right]);
                break;
            } else if (total < target) {
                // 小了，左边往后移动
                left++;
            } else {
                right--;
            }
        }
        return result;
    }
};
```