### 解题思路

map大法好

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
    const map = new Map()
    for (let i = 0; i < nums.length; i++) {
        if (map.has(nums[i])) {
            map.set(nums[i], 3)
        } else {
            map.set(nums[i], 1)
        }
    }
    for (let [key, val] of map) {
        if(val === 1) return key
    }
};
```