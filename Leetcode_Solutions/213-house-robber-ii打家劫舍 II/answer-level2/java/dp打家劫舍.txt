### 解题思路
子问题：第1到第i个房屋能偷窃的最高金额；
状态方程：thief[i]表示当前节点子问题最优解；
状态转移方程：比较thief[i-1]与thief[i-2] + nums[i]，取最高的作为当前最高的点；
注意状态转移方程分析的技巧，往前看一到多个子问题的最优解，
因为dp与贪心算法不同点在于，贪心只保存前一个点的情况，后一个点基于前一个点进行求解
而dp则是将子问题所有的最优情况进行了保存，所以你可以往前看任意多个点

### 代码

```java
class Solution {
    public int rob(int[] nums) {
       
        if (nums == null || nums.length == 0) {
            return 0;
        }
        if (nums.length == 1) {
            return nums[0];
        }
        if (nums.length == 2) {
            return Math.max(nums[0], nums[1]);
        }
        int thiefOne = nums[0];
        int thiefTwo = nums[0];
        // 分两种情况进行，第一种是偷了1号房屋，
        for (int i=2;i<nums.length - 1;i++) {
            int temp = thiefTwo;
            thiefTwo = Math.max(thiefTwo, thiefOne + nums[i]);
            thiefOne = temp;
        }
        int max = thiefTwo;
        thiefOne = 0;
        thiefTwo = nums[1];
        // 一种是没有偷窃
        for (int i=2;i<nums.length;i++) {
            int temp = thiefTwo;
            thiefTwo = Math.max(thiefTwo, thiefOne + nums[i]);
            thiefOne = temp;
        }
        return Math.max(max, thiefTwo);
    }
}
```