### 解题思路
无他暴力

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    var res = []; 
    for(var i = 0; i < nums.length; i++) {
        var index = nums.findIndex((item, index) => index > i && item === target - nums[i]);
        if (index !== -1) res.push(i, index); 
    }
    return res;
};
```