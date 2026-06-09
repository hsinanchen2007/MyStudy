### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    const len = nums.length;
    if(len <= 0){
        return 0
    }
    let sum = nums[0],
        maxSum = nums[0];
    for(let i=1; i<len; i++){
        sum = sum > 0 ? sum + nums[i] : nums[i]
        maxSum = sum > maxSum ? sum : maxSum
    }
    return maxSum
};
```