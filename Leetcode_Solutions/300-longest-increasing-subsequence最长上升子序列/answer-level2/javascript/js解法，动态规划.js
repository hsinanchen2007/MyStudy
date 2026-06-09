### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var lengthOfLIS = function(nums) {
    const len = nums.length
    if (len === 0) {
        return 0
    }
    if (len === 1) {
        return 1
    }
    const res = new Array(len).fill(1)
    for (let i = 1; i < len; i++) {
        for (let j = 0; j < i; j++) {
            res[i] = Math.max(res[i], nums[i] > nums[j] ? res[j] + 1 : 1)
        }
    }
    res.sort((a, b) => b - a)
    return res[0]
};
```