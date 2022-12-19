### 解题思路
此处撰写解题思路
记录下自己的思考过程：
看题目，连续自序列最大乘积，想到动态规划解决。
第一步，寻找DP状态：
首先，DP状态代表中间一个位置，目前序列，连续自序列的最大值。
但是本题有个特殊的地方，序列里面的数可以为正数，也可以为负数，负负得正，也就是说当前的最大值，下一次遇到负数，可以变为最小值（负数最大值），再一次遇到负数，就又变为最大值。所以，我这里思考，应该记录两个DP状态，一个记录最大值，一个记录最小值。
第二步，寻找DP状态转移方程：
当位于任意一个位置，目前最大值，考虑到元素为负的情况：
正数最大值：dpMax ＝ max{dpMax * nums[i],nums[i],dpMin * nums[i]}
同理
负数最大值：dpMin ＝ min｛dpMax * nums[i],nums[i],dpMin * nums[i]｝
最后，考虑特殊情况，书写代码。

### 代码

```java
class Solution {
    public int maxProduct(int[] nums) {
        if(nums == null){
            return 0;
        }
        int length = nums.length;
        int dpMax = 1;
        int dpMin = 1;
        int max = Integer.MIN_VALUE;
        for(int i = 0; i < length; i++){
           int tmpDpMin = dpMin;
           int tmpDpMax = dpMax; 
           dpMax = Math.max(tmpDpMin * nums[i],Math.max(dpMax * nums[i],nums[i]));
           dpMin = Math.min(tmpDpMax * nums[i],Math.min(dpMin * nums[i],nums[i])) ;
           max = Math.max(dpMax,max);
        }
        return max;
    }
}
```