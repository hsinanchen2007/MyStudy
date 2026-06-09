### 解题思路
先做去重处理，如果去重后的数组长度等于原本数组长度，直接返回数组的第一个元素
否则根据数组的find特性，找到第一个符合要求（利用indexOf找到当前元素第一个出现的下标与当前数组遍历的下标是否相等）的元素立即返回

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findRepeatNumber = function(nums) {
    let setNums = [...new Set(nums)]
    if (setNums.length === nums.length) {
        return setNums[0]
    } else {
        const result = nums.find((itm, idx) => nums.indexOf(itm) !== idx)
        return result
    }
};
```