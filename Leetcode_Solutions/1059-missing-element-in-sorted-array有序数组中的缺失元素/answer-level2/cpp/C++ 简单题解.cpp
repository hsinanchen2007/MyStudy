```
class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int d = 0;
        for (int i = 1; i < nums.size(); ++i) {
            d += max(0, nums[i] - nums[i - 1] - 1);
            if (d >= k) {
                return nums[i] - 1 - (d - k);
            }
        }
        return nums.back() + k - d;
    }
};
```

![image.png](https://pic.leetcode-cn.com/68bc59f53daa40e6f9f5e0e6b78b69ede344a051ee931837e0c241541832c54f-image.png)
