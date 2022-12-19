### 解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var singleNumber = function(nums) {
    const len = nums.length
    const map = new Map()
    const res = []
    for (let i = 0; i < len; i++) {
        const num = nums[i]
        if (map.has(num)) {
            map.delete(num) 
        } else {
            map.set(num, 1)
        }
    }
    map.forEach((val, key) => {
        res.push(key)
    })
    return res
};
```