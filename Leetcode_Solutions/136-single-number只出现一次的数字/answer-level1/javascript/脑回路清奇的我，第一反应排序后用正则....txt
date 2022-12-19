### 解题思路
一行代码搞定，忽略执行效率哈哈233333

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
    return (nums.sort().toString()+',').replace(/(-?\d+,)\1/g,"").split(',')[0];
};
```