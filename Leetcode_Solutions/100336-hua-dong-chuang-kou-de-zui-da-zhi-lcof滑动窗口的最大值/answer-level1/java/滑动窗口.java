### 解题思路

在暴力的基础优化。

![image.png](https://pic.leetcode-cn.com/34ff8486c495aa0284b95aa7342ad70956909e96d2f8108678b7427e196287ab-image.png)

### 代码

```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if (nums == null || k == 0 || nums.length < k) return new int[0];
        int[] result = new int[nums.length - k + 1];
        result[0] = calMaxVal(nums, 0, k - 1);
        for (int i = k; i < nums.length; i++) {
            if (nums[i] >= result[i - k]) {
                result[i - k + 1] = nums[i];
            } else if (nums[i - k] < result[i - k]) {
                result[i - k + 1] = result[i - k];
            } else {
                result[i - k + 1] = calMaxVal(nums, i - k + 1, i);
            }
        }
        return result;
    }

    private int calMaxVal(int[] nums, int from, int to) {
        int result = nums[from];
        for (int i = from; i <= to; i++) {
            result = Math.max(result, nums[i]);
        }
        return result;
    }
}
```