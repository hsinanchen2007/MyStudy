### 代码

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // 先判断是否缺1
        bool flag = true;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                flag = false;
                break;
            }
        }
        if (flag) return 1;

        // 不缺1，且数组只有一个元素的情况下，缺2
        if (n == 1) return 2;

        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] > n) nums[i] = 1;
        }

        for (int i = 0; i < n; i++) {
            int ind = abs(nums[i]);
            if (ind == n) {
                nums[0] = -abs(nums[0]);
            } else {
                nums[ind] = -abs(nums[ind]);
            }
        }

        // 找到第一个为正数的下标 
        for (int i = 1; i < n; i++) {
            if (nums[i] > 0) return i;
        }
        if (nums[0] > 0) return n;

        return n + 1;
    }
};
```