### 解题思路


### 代码

```cpp
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (nums.empty() || nums.size() ==0) {
            return 0;
        }
        int curCount = 1;
        int count = 0;
        int beginIndex = 0;
        for (int endIndex = 0; endIndex < nums.size(); endIndex++) {
            curCount *= nums[endIndex];
            while (curCount >= k && beginIndex < endIndex) {
                curCount /= nums[beginIndex];
                beginIndex++;
            }
            if (curCount < k) {
                count += endIndex - beginIndex + 1;
            }
        }
        return count;
    }
};
```