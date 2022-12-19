### 解题思路
一开始没好好读题目，以前是取余数，仔细看才发现是取数组值的余数

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findNumbers = function(nums) {
    return nums.filter(item=> !(String(item).length % 2)).length
};
```