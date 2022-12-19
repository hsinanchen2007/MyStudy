### 解题思路
![image.png](https://pic.leetcode-cn.com/ac3bce10ceaaa7863d996e9413ca77cc0f495a5f53c9ee7b80466859bf6c90df-image.png)
使用除法来解的，主要是要注意nums中是否有0，有几个0
### 代码

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int ss = 1;
        int zero_nums = 0;
        for (auto num : nums) {
            if (num == 0) {
                zero_nums++;
                continue;
            }
            ss *= num;
        }
            
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (zero_nums > 1) {
                nums[i] = 0;
            } else if (nums[i] == 0) {
                nums[i] = ss;
            } else if (zero_nums > 0) {
                nums[i] = 0;
            } else {
                nums[i] = ss / nums[i];
            }  
        }
        return nums;
    }
};
```