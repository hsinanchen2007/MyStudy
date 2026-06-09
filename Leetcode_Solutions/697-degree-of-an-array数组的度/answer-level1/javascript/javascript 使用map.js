### 解题思路
使用map来统计不同数字的索引，最终找到出现最多的数字中首尾索引差值最小的
### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
 var findShortestSubArray = function(nums) {
    const len = nums.length
    const map = new Map()
    const temp = []
    let max = 0
    let res = Infinity
    // 统计不同数的索引数组
    for (let i = 0; i < len; i++) {
        const num = nums[i]
        let arr
        if (map.has(num)) {
            arr = map.get(num)
        } else {
            arr = []
        }
        arr.push(i)
        map.set(num, arr)
        max = Math.max(max, map.get(num).length)
    }
    // 找到复合数组度的数字中，首尾索引差值最小的
    map.forEach(item => {
        if (item.length === max) {
            res = Math.min(res, item[item.length - 1] - item[0] + 1)
        }
    })
    return res
};
```