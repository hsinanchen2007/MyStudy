### 解题思路
双指针
对于排序好的数组，从首位向中间逼近

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>res;
        if(nums.size() < 2 && nums.empty()) return  res;
        int left = 0, right = nums.size() - 1, sum;
        while(left < right) {
            if(target == nums[left] + nums[right]) {
                res.push_back(nums[left]);
                res.push_back(nums[right]);
                break;
            } else if(target > nums[left] + nums[right])
                left++;
            else
                right--;
        }
        return res;
    }
};
```