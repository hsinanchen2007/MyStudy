### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        if (null == nums || 0 == nums.length)
            return 0;

        int maxSum = nums[0];
        int tmpSum = 0;

        for (int n: nums) {
            if (tmpSum < 0)
                tmpSum = n;
            else tmpSum += n;
            maxSum = Math.max(maxSum, tmpSum);
        }
        return maxSum;
    }
}
```