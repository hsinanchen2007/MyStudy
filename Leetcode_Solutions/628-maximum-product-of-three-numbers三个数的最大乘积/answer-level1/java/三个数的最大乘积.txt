### 解题思路
自己写个半死，一看答案，卧槽。直接调用api。

### 代码

```java
class Solution {
    public int maximumProduct(int[] nums) {
        java.util.Arrays.sort(nums);
		return java.lang.Math.max(nums[0] * nums[1] * nums[nums.length - 1],
				nums[nums.length - 1] * nums[nums.length - 2] * nums[nums.length - 3]);
    }
}
```