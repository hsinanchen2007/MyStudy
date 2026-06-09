### 解题思路
双100%

### 代码

```cpp
class Solution {
public:
    int massage(vector<int>& nums) {
        size_t n = nums.size();
        if (n == 0) {
            return 0;
        } else  if (n == 1) {
            return nums[0];
        } 
        int beforeYesterday = 0;
        int yesterday = nums[0];
        int res = 0;
        for (int i = 1; i < n; i++) {
            res = max(beforeYesterday + nums[i],yesterday);
            beforeYesterday = yesterday;
            yesterday = res;
        }
        return res;
    }
};
```