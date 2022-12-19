**^的运算法则：**
只有在两个比较的位不同时其结果是1，否则结果为0
即“两个输入相同时为0，不同则为1”！

```
/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNonDuplicate = function(nums) {
    let t = 0;
    // 两个输入相同时为0，不同则为1
    for(let i = 0; i < nums.length; i++) {
        t = t ^ nums[i];
    }
    return t;
};
```
