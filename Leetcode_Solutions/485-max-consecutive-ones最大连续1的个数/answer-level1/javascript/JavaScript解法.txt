## 题目剖析

> 给定一个二进制数组， 计算其中最大连续1的个数。

## 解题思路

用一个变量 ``count`` 计数，用一个变量 ``res`` 记录结果

## 示例代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxConsecutiveOnes = function(nums) {
    let count = 0, res = 0
    for (const num of nums) {
        if (num === 1) {
            count++
        } else {
            count = 0
        }
        res = Math.max(res, count)
    }
    return res
};
```