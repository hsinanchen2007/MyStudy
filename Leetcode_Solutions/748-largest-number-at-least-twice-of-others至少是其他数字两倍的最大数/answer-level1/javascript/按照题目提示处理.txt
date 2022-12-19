### 解题思路
1. 找最大值
2. 除最大值的那个元素外，若有max<num*2则返回-1

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var dominantIndex = function(nums) {
    let max = Math.max.apply(null, nums);
    for (const num of nums) {
        if (max !== num && max < (num * 2)) {
            return -1
        }
    }
    return nums.findIndex(val => val === max)
};
```