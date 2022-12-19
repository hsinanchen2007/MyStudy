### 解题思路


### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var smallerNumbersThanCurrent = function(nums) {
    const len = nums.length
    const map = new Map()
    let temp = [...nums]
    temp.sort((a, b) => a - b)
    const tLen = temp.length
    const res = []
    for (let i = 0; i < tLen; i ++) {
        const item = temp[i]
        !map.has(item) && map.set(item, i)
    }
    for (let i = 0; i < len; i ++) {
        const item = nums[i]
        res.push(map.get(item))
    }
    return res
};
```