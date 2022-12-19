### 解题思路
双指针法，做过最简单的一道题

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
// 根据指定的值，在数组中删除指定的值
var removeElement = function(nums, val) {
    if (nums.length == 0) {
            return 0;
        }
        var i = 0;
        for (var j = 0; j < nums.length; j++) {
            // 如果不符合，则把不符合的存到数组里面
            if (nums[j] != val) {
                nums[i++] = nums[j];
            }
        }
        return i;
};
```