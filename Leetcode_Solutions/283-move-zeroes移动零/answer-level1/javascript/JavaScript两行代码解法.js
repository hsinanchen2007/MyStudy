思路: 
    最终需要的结果是非零位置保持原顺序，为零位置移动到最后。因此只需要先把原数组中的`0`移除，再补足移除后的0的位置。代码如下：

```/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
    let nonZeroNums = nums.filter(e => e != 0)
    nums.forEach((e,i) => nums[i] =  i < nonZeroNums.length ? nonZeroNums[i] : 0 )
};
```