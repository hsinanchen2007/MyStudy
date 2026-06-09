### 解题思路
注意，这个判断的时候要记着有最小值的概念，因为最小值遇到负数，可能是最大值
第二注意就是判断最大最小的时候，记着判断当前变量

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxProduct = function(nums) {
    if(nums.length ==0){return 0}
    let max = nums[0];
    let max1 = nums[0];
    let min2 = nums[0];
    let temp = nums[0]
    for(let i = 1; i< nums.length; i++){
        max1 = Math.max(nums[i], max1 * nums[i], min2 * nums[i])
        min2 = Math.min(nums[i], temp * nums[i], min2 * nums[i])
        temp = max1
        max = Math.max(max, max1)
    }

    return max
};
```