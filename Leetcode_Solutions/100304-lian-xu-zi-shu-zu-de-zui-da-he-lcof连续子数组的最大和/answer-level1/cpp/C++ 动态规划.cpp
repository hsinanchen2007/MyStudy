```
f(0) = nums[0]
f(1) = max(nums[1], nums[1]+f(0))
f(n) = max(nums[n], nums[n]+f(n-1))
result = max(f(0), f(1), ... , f(n))
```

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxValue = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] > 0) nums[i] += nums[i-1];
            if (nums[i] > maxValue) maxValue = nums[i];
        }
        return maxValue;
    }
};
```