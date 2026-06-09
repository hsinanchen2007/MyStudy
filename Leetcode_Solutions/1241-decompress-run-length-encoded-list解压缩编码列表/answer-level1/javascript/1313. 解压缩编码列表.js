### 解题思路
跑了几次es6解构比concat速度快一些

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var decompressRLElist = function (nums) {
    let result = []
    for (let i = 0; i < nums.length / 2; i++) {
        result = [...result, ...(new Array(nums[2 * i])).fill(nums[2 * i + 1])]
    }
    return result
};
```