### 解题思路
每遍历一个元素，计算其是否为中心元素：
中心元素的性质：sum - cur - cur_left_sum = cur_left_sum

### 代码

```cpp
class Solution {
public:
    int pivotIndex(vector<int>& nums) {        
        int sum = 0;
        int left_sum = 0;

        // 1. 计算总和
        for (auto n : nums) sum += n;
        
        for (int i = 0; i < nums.size(); i++) {
            // 2. 判断：sum - nums[i + 1] - left_sum == left_sum
            if (sum - nums[i] - left_sum == left_sum) 
                return i;

            left_sum += nums[i];
        }

        return -1;
    }
};
```