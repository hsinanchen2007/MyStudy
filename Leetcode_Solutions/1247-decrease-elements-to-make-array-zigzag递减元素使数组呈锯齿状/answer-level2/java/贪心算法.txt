### 解题思路
迭代解决，要注意只能减不能加。
![image.png](https://pic.leetcode-cn.com/d70c4a34fabef35358fc07d971772146c2ba14b6f57b905fd14b242c6ab6c9fb-image.png)

### 代码

```java
class Solution {
    public int movesToMakeZigzag(int[] nums) {
        int result = Integer.MAX_VALUE;
        for (int k = 0; k < 2; k++) {
            int result1 = 0;
            int pre = nums[0];
            for (int i = 1; i < nums.length; i++) {
                if (i % 2 == k && nums[i] <= pre) {
                    result1 += (pre - nums[i] + 1);
                    pre = nums[i]; //只能减不能加
                } else if (i % 2 == (1 - k) && nums[i] >= pre) {
                    result1 += (nums[i] - pre + 1);
                    pre = pre - 1;
                } else {
                    pre = nums[i];
                }
            }
            result = Math.min(result, result1);
        }

        return result;
    }
}
```