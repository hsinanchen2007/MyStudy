### 解题思路
寻找每段连续递增子数组，记录长度，与上次的子数组比较长度，取较大者。

### 代码

```cpp
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        int max_len = 1;
        int len = 1;

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                len++;
                max_len = max(max_len, len);
            } else {
                len = 1;
            }   
        }

        return max_len;
    }
};
```