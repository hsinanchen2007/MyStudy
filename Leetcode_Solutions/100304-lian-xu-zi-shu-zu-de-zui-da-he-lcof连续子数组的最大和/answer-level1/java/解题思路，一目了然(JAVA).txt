### 解题思路
这题主要考虑两种情况：
    1.第一种，数组有正有负的情况，这时我们遍历数组，累计求和total, 如果total小于0，则直接舍弃前面的和，重新从0开始计算，确保子数组和最大
    2.第二种，数组只有负数的元素，那么最大的子数组和，肯定就是数组中最大的负数。

时间复杂度：O(n), 空间复杂度：O(n)

![WeChatcfb7ab578afb328d8d438cf7002a7772.png](https://pic.leetcode-cn.com/5d7045c3e053424174a22325580fec2872b3b20f0b66033926d873256bfaf5d3-WeChatcfb7ab578afb328d8d438cf7002a7772.png)

### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        int total = 0;
        // 正数的最大值
        int max = -1;
        // 针对数组元素全是负的情况，维护一个min，存的是负数的最大值
        int min = -Integer.MAX_VALUE;
        for (int i = 0; i < nums.length; i++) {
            total += nums[i];
            if (total <= 0) {
                min = Math.max(total, min);
                total = 0;
            } else {
                max = Math.max(max, total);
            }
        }

        // 如果max >= 0，说明存在total大于零的情况，max > min
        return max >= 0 ? max : min;
    }
}