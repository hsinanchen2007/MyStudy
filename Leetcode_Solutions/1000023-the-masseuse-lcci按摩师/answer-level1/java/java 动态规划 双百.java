### 解题思路
1、计算每个下标的最大值，初始化前三位，最后两位最大值就是结果。
2、最多能跳两位，因为跳三位的话中间肯定还能再加一位。
3、每位的最大值产生是0+3、1+3、2的最大值。
4、以上说的位数指的是数组下标。

### 代码

```java
class Solution {
    public int massage(int[] nums) {
        boolean isEmpty = nums == null || nums.length == 0;
        if (isEmpty) {
			return 0;
		}
		if (nums.length == 1) {
			return nums[0];
		}
        if (nums.length == 2) {
			return Math.max(nums[0], nums[1]);
		}
		nums[2] = Math.max(nums[0] + nums[2], nums[1]);
		for (int i = 3; i < nums.length; i++) {
			int tmp = Math.max(nums[i - 2] + nums[i], nums[i - 1]);
			nums[i] = Math.max(nums[i - 3] + nums[i], tmp);
		}
		return Math.max(nums[nums.length - 1], nums[nums.length - 2]);
    }
}
```