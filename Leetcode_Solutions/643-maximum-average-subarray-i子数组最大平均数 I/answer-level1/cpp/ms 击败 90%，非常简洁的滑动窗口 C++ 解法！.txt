### 解题思路
滑动长度为 K 的窗口解法，后一个窗口的和可以通过前一个窗口计算得到，比如 k = 3:
1 2 3 4 5
初始窗口和：1 + 2 + 3 = 6
滑动一次窗口的和：2 + 3 + 4 = 9 = 上一个窗口的和 6 (1 + 2 + 3) - 上一个窗口的第一个数 1 + 当前窗口的最后一个数 4

非常好理解，代码如下。

### 代码

```cpp
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum_k = 0;
        for (int i = 0; i < k; i++)
            sum_k += nums[i];

        double max_sum_k = sum_k;
        // 滑动窗口 1 2 3 4 5
        // 1 + 2 + 3 = 6
        // 2 + 3 + 4 = 9 = 6(1 + 2 + 3) - 1 + 4
        for (int i = k; i < nums.size(); i++) {
            sum_k = sum_k - nums[i - k] + nums[i];
            max_sum_k = max(max_sum_k, sum_k);
        }

        return max_sum_k / k;
    }
};
```