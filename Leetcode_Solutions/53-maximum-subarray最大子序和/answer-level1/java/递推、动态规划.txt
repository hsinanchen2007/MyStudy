### 解题思路
定义f(n)为到下标n元素为止的最大连续子序列之和，那么f(n+1) = max(f(n)+nums[n+1],nums[n+1]),意思就是到下标n+1位置的最大子序列取决于前一个元素的最大子序列和加上自己后比自身元素另起一个序列大还是小，如果另起序列大，那就是nums[n+1], 否则就是前一个元素的最大子序列加上自己。
计算出每个下标为止的最大子序列和，那么取所有的最大值就可以了，因为我们最终要的结果只是一个最大值，而不是每个下标出的最大子序列和，所以只需要用一个int值记录max就可以了。

### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        int res = nums[0];
        int curMax = nums[0];
        for(int i=1; i < nums.length; i++){
            curMax = Math.max(curMax + nums[i],nums[i]);
            res = Math.max(curMax, res);
        }
        return res;
    }
}
```