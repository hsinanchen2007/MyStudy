时间复杂度为O(n)的解法：
遍历数组nums, 
1、累加计算前n个连续数字之和（从第一个开始累加）sum,
2、将值最小且小于0的sum记录为min，
3、在遍历的过程中不断计算更新当前的sum-min,得到最大子序和max, 而且不断计算更新当前的min

代码如下：

```
代码块var maxSubArray = function(nums) {

    let max = nums[0];
    let min = 0;
    let sum = 0;
    for(let i=0; i<nums.length; i++) {
        sum += nums[i];
        max = Math.max(max, sum-min);
        min = Math.min(sum, min);
    }
    return max;
    
};
```
