### 解题思路
1、通过求余2来判断是否为偶数
2、通过filter函数得到偶数的个数

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findNumbers = function(nums) {
    return nums.filter(v=>v.toString().length%2===0).length
};
```