### 解题思路


### 代码

```cpp
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        int sum_l = 0;
        
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        for (int i = 0; i < nums.size(); i++) {
            if (sum_l == sum - sum_l - nums[i])
                return i;
            sum_l += nums[i];
        }
        return -1;
    }
};
```