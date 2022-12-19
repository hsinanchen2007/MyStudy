### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        vector<int> res;
        while(left < right)
        {
            if((nums[left] + nums[right]) == target)
            {
                res.push_back(nums[left]);
                res.push_back(nums[right]);
                break;
            }
            else if((nums[left] + nums[right]) < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return res;
    }
};
```