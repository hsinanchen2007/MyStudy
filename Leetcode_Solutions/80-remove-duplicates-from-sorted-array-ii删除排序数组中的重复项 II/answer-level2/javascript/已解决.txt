### 解题思路
利用数组删除指定元素，并判断左右是否和本身相等。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function (nums) {
    for (let i = 1; i < nums.length; i++) {
        if (nums[i] == nums[i - 1] && nums[i] == nums[i + 1]) {
            nums.splice(i, 1);
            i--;
        }
    }
    return nums.length;
};
```