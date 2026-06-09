### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
第一道题
var twoSum = function(nums, target) {
      let arr = [];
        nums.forEach((element, index) => {
          let other = target - element;
          let i = nums.lastIndexOf(other);
          if (i > -1 && index < i) {
            arr = [index, i];
          }
        });
        return arr;
};
```
