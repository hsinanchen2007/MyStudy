### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var decompressRLElist = function (nums) {
    let arr = [];
    for (let i = 0; i < nums.length; i += 2) {
        arr.push(...new Array(nums[i]).fill(nums[i + 1]));
    }
    return arr;
};
```