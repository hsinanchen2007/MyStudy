### 解题思路
先记录各个数值数字个数到nums数组中
若超过1个则需要nums[i]-1个数值作move操作，并加到下一个数值的计数中

例如第一步操作后nums中0,1,2各有三个数[2,2,2]
循环后变成[1,3,2], [1,1,4], [1,1,1,3], ...
### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number}
 */
var minIncrementForUnique = function(A) {
    let count = 0
    let nums = []
    for(let num of A) {
        if(nums[num]) nums[num]++
        else nums[num] = 1
    }
    for(let i=0; i<nums.length; i++) {
        if(nums[i]>1) {
            if(nums[i+1]) nums[i+1] += (nums[i]-1)
            else nums[i+1] = nums[i]-1
            count += nums[i]-1
        }
    }
    return count
};
```