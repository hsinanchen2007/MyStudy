### 解题思路
for循环中i与lastIndexOf得到的index不相等，说明有相同元素

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function (nums) {
    let len = nums.length
    for (let i = 0; i < len; i++) {
        if (nums.lastIndexOf(nums[i]) >=0 &&nums.lastIndexOf(nums[i]) !== i ){
            return true
        }
    }
    return false
};
```