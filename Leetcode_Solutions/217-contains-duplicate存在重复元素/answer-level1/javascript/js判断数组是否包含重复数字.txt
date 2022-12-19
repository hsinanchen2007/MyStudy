### 解题思路
利用js中Set会自动去重的特点，先利用原数组构造Set,然后比较原数组的length和构造出来的Set的size是否相等，就能判断原数组是否包含重复数字

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
  const tmpSet = new Set(nums);
  return tmpSet.size !== nums.length;
};
```