
基本思路：

对于每一列，找出当前列左边的最大值和右边的最大值，如果 `curHeight < min(leftMax, rightMax)`，则当前列水量为`min(leftMax, rightMax) - curHeight`，否则，当前不可能盛水。因此，首先需要构建左边和右边最大值的数组。实际上，左边最大值数组不需要提前构建，也不用数组，在求水量的过程中动态更新即可。

```
class Solution {
   public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) return 0;
        int n = height.size();

        vector<int> rightMax(height.size());
        rightMax[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i + 1]);
        }

        int leftMax = 0;
        int res = 0;
        for (int i = 1; i < n - 1; i++) {
            leftMax = max(leftMax, height[i - 1]);
            int lowBound = min(leftMax, rightMax[i]);
            if (height[i] < lowBound) {
                res += (lowBound - height[i]);
            }
        }
        return res;
    }
};
```

时间复杂度：O(n)
空间复杂度：O(n)

![image.png](https://pic.leetcode-cn.com/4ae5d9404d84b1dff6b65aa3716ddc4e67033a701c51a70cb2059e60046483e2-image.png)
