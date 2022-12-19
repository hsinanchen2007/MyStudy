### 解题思路
1. 每次遇到不会的题就很激动，有要学新东西了T T。。
2. 想到用动态规划，但是只想着维护一个数组，怎么想怎么想不出来，觉得是不是不能用冻柜。
3. 还是可以的，维护一个不行就维护两个，就好像没有钱解决不了的问题一样。。。
4. 循环的关键是遇到负数时，最大最小值需要更改，因为是求以当前元素结尾的子序列的最大值，因此必须得有它。

### 代码

```java
class Solution {
    public int maxProduct(int[] nums) {
        if(nums == null || nums.length == 0) return 0;
        int max = 1, min = 1, res = Integer.MIN_VALUE; //要维护一个全局最大值
        for(int i = 0; i < nums.length; i++){
            if(nums[i] < 0){ //当前元素为负数时，交换最大最小值，然后乘以当前数组。
                int t = max;
                max = min;
                min = t;
            }
            max = Math.max(nums[i], max * nums[i]);
            min = Math.min(nums[i], min * nums[i]);
            res = Math.max(max, res);
        }
        return res;
    }
}
```