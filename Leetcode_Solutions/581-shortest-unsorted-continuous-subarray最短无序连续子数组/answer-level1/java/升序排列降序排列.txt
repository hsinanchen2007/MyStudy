### 解题思路
题目没指明生序排列还是降序排列
故这种情况都需要考虑

### 代码

```java
class Solution {
    public int findUnsortedSubarray(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }
        //从左向右遍历
        int max = nums[0];
        int right  = 0;
        //从左向右遍历
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] < max) {
                right = i;
            }
            max = Math.max(max, nums[i]);
        }

        //从右向左遍历
        int min   = nums[nums.length-1];
        int left  = 0;
        for (int i = nums.length - 2; i >= 0; i--) {
            if (nums[i] > min) {
                left = i;
            }
            min = Math.min(min, nums[i]);
        }

        return left == right ? 0 : Math.abs(right - left) + 1;
    }
}
```