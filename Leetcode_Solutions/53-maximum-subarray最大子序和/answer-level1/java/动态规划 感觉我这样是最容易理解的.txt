### 解题思路
首先，定义sum，当前最优解temp，循环遍历一遍数组，动态规划方程是 temp = ((temp+nums[i])>nums[i])?(temp+nums[i]):nums[i]
即 当前最优解 为 当前数组值加上之前的最优解 与 当前值 间的较大者，假如当前最优解大于sum，则更新最优解。

### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        int sum = nums[0];
        int temp = nums[0];
        for (int i = 1; i < nums.length; i++) {
            temp = ((temp+nums[i])>nums[i])?(temp+nums[i]):nums[i];
            if(temp>sum)sum = temp;
        }
        return sum;
    }
}
```