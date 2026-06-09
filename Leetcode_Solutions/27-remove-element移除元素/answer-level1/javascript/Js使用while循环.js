### 解题思路
用循环生怼的话会出现index不归零的问题，for也同理，所以就想到用while循环自主控制index，56ms干掉96.66%

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function (nums, val) {
    let i = 0
    while (i < nums.length) {
        if (nums[i] === val) {
            nums.splice(i, 1)
            i = 0
        } else {
            i += 1
        }
    }

    return nums.length
};
```