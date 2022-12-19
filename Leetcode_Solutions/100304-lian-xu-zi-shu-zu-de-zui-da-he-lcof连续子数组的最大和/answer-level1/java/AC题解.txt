### 解题思路
执行用时 :1 ms, 在所有 Java 提交中击败了100.00% 的用户
内存消耗 :58 MB, 在所有 Java 提交中击败了100.00%的用户
思路见注释

### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        if (nums == null || nums.length < 1) {
            throw new IllegalArgumentException("Array must contain an element");
        }
        // 记录最大的子数组和，开始时是最小的整数
        int max = Integer.MIN_VALUE;
        // 当前的和
        int curMax = 0;
        // 数组遍历
        for (int i : nums) {
            // 如果当前和小于等于0，就重新设置当前和
            if (curMax <= 0) {
                curMax = i;
            }
            // 如果当前和大于0，累加当前和
            else {
                curMax += i;
            }
 
            // 更新记录到的最在的子数组和
            if (max < curMax) {
                max = curMax;
            }
        }
        return max;
    }
}
```