### 解题思路
此处撰写解题思路
结合 ES6 Set数据结构的特有属性，先去重在对比length
### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
   return nums.length !== new Set(nums).size;
};
```