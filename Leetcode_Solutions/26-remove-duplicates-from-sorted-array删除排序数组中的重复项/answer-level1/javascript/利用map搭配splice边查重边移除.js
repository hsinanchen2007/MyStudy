### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    let map = {};
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] in map) {
            nums.splice(i, 1);
            i--;
        } else {
            map[nums[i]] = true;
        }
    }
    return nums.length
};
```
利用map搭配splice边查重边移除