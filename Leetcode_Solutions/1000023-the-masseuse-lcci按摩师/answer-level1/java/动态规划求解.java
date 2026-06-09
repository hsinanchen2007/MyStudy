### 解题思路
使用动态规划进行求解，在第i个的顾客之前，按摩师可以服务第i - 3个顾客或第i - 2个顾客，
因此设置动态数组sum[n](n = nums.length)进行规划，
首先设置sum[0] = nums[0], sum[1] = nums[1], sum[2] = sum[0] + nums[2];
并另外设置最大值max = Math.max(sum[1], sum[2]);
而后从i = 3遍历数组，将sum[i] = Math.max(sum[i - 2], sum[i - 3]) + nums[i];即可
而后求max = Math.max(sum[i], max);

### 代码

```java
class Solution {
    public int massage(int[] nums) {
        if(nums == null || nums.length == 0) return 0;
        if(nums.length < 3){
            return nums.length == 1 ? nums[0] : Math.max(nums[0], nums[1]);
        }
        int n = nums.length;
        int[] sum = new int[n];
        sum[0] = nums[0];
        sum[1] = nums[1];
        sum[2] = sum[0] + nums[2];
        int max = Math.max(sum[1], sum[2]);
        for(int i = 3; i < n; i ++){
            sum[i] = Math.max(sum[i - 2], sum[i - 3]) + nums[i];
            max = Math.max(sum[i], max);
        }
        return max;
    }
}
```