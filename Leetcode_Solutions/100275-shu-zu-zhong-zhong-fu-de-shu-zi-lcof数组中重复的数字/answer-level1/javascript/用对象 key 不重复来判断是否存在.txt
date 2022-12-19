### 解题思路
用对象 key 不重复来判断是否存在

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findRepeatNumber = function(nums) {
    const result = {};
    let repeat;
    nums.find(i => {
      if (result[i] === 1) {
        repeat = i;
        return true;
      }
      result[i] = 1;
    })
    return repeat;
};
```