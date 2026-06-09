### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int result = 1;
        int result_temp = 0;
        int last = 0;
        int last_prev = 0;
        for (int i = 0; i < nums.size()-1; i++) {
            if (nums.size()-i <= result)
                break;
            last = nums[i];
            last_prev = nums[i];
            result_temp = 1;
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[j] > last) {
                    last_prev = last;
                    last = nums[j];
                    result_temp++;
                } else if (nums[j] > last_prev)
                    last = nums[j];
            }
            if (result_temp >= result)
                result = result_temp;
        }
        return result;
    }
};
```