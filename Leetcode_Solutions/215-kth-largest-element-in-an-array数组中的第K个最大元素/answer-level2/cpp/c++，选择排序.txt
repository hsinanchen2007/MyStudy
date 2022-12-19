### 解题思路
只对前k个最大数选择出来排序，性能还不如sort

### 代码

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        for (int i = 0; i < k; ++i) {
            int maxIndex = i;

            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[j] > nums[maxIndex]) {
                    maxIndex = j;
                }
            }

            swap(nums[i], nums[maxIndex]);
        }

        return nums[k - 1];
    }
};
```