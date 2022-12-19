### 解题思路
![屏幕快照 2020-03-24 16.35.35.png](https://pic.leetcode-cn.com/2587ffb8b9370a4900840c917227085cacd622a0a5ca8108750fcd296d180990-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-03-24%2016.35.35.png)


### 代码

```java
class Solution {
    public int massage(int[] nums) {
        // 特判
        if (nums.length == 0) {
            return 0;
        }
        if (nums.length == 1) {
            return nums[0];
        }
        // 将前两位最大的放在第二位
        nums[1] = Math.max(nums[0], nums[1]);
        for (int i = 2; i < nums.length; i++) {
            // 比较 当前位置的值+前两位的值 和 前一位值，将大的设置给当前
            nums[i] = Math.max(nums[i - 1], nums[i] + nums[i - 2]);
        }
        return nums[nums.length - 1];
    }

}
```