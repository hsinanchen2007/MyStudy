DP:执行用时 : 0 ms , 在所有 Java 提交中击败了 100.00% 的用户
内存消耗 :37.3 MB, 在所有 Java 提交中击败了5.09%的用户

### 解题思路
假设此时在[i]位，把[0~i]作为一个数组，求该数组能偷的最大值，求出后写入[i]；
由于[0~i-1]的最大值已经写在了[i-1],所以只需要比较[i-1]和（[i] + [i-1]）的大小把大的那个写入[i]

### 代码

```java
class Solution {
    public int rob(int[] nums) {
        if(nums.length == 0)
            return 0;
        
        if(nums.length == 1)
            return nums[0];
        
        if(nums.length == 2)
            return Math.max(nums[0], nums[1]);

        // 第2个子数组手动算一下最大值
        nums[1] = Math.max(nums[0], nums[1]);

        for (int i = 2; i < nums.length; i++) {
            int tmp = nums[i] + nums[i-2];
            nums[i] = Math.max(nums[i-1], tmp);       
        }

        return nums[nums.length-1];
    }
}
```