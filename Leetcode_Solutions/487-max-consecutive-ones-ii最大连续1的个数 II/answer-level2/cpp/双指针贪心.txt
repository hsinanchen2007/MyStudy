### 解题思路
在0的个数不超过1的情况下，右指针尽量向后移动。如果0的个数超过1，再向后移动左指针，直到0的个数小于1。

在整个过程中，不断更新最优解。

### 代码

```cpp
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        int ans = 0, count = 0;
        while (l <= r && r < n) {
            while (r < n && count <= 1) {
                count += nums[r] == 0;
                if (count <= 1)
                    ans = max(ans, r - l + 1);
                r++;
            }
            while (count > 1) {
                count -= nums[l] == 0;
                l++;
            }
        }
        return ans;
    }
};
```