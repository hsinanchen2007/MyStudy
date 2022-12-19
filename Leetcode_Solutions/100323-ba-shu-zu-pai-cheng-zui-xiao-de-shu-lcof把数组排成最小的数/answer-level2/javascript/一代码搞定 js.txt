### 解题思路
对比相加后的数谁更小 降序排列

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {string}
 */
var minNumber = function(nums) {
    return nums.sort((a, b) => (a + '' + b - 0) - (b + '' + a - 0)).join('')
};
```