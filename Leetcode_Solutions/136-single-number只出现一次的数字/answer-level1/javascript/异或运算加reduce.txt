### 解题思路
相同的数异或为0，0异或任何数为任何数，最后只会剩下落单的那个数

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
    //相同的数异或为0，0异或任何数为任何数，最后只会剩下落单的那个数
    return nums.reduce((a,b)=>a^b)
};
```
