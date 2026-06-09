### 解题思路

用map

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    const map = new Map()
    let res = 0
    for (let i = 0; i < nums.length; i++) {
        if (map.has(nums[i])) {
            let count = map.get(nums[i])
            map.set(nums[i], count + 1)
        } else {
            map.set(nums[i], 1)
        }
        res = Math.max(res, map.get(nums[i]))
    }
    for (let key of map.keys()) {
        if (map.get(key) === res) return key
    }
};
```