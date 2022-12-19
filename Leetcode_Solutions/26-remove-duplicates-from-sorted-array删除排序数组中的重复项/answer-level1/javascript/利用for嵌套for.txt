### 解题思路
双层循环，外层循环元素，内层循环时比较值。值相同时，则删去这个值。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function (nums) {
    for (var i = 0; i < nums.length; i++) {
        for (var j = i + 1; j < nums.length; j++) {
            if (nums[i] == nums[j]) {
                nums.splice(j, 1);
                j--;
            }
        }
    }
    return nums.length
};
```