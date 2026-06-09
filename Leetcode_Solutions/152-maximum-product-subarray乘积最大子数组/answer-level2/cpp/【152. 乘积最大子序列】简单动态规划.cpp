## 思路
当前值为负数时，可能使原先最大值变为最小值，最小值变为最大值，所以需要维护当前最小值，如果当前值为负数，则交换当前最大值和最小值。

### 代码
```c++
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        int res = INT_MIN, imax = 1, imin = 1;        
        for (int i = 0; i < size; ++i) {
            if (nums[i] < 0) swap(imax, imin);
            imax = max(imax * nums[i], nums[i]);
            imin = min(imin * nums[i], nums[i]);
            res = max(res, imax);
        }
        return res;
    }
};
```
