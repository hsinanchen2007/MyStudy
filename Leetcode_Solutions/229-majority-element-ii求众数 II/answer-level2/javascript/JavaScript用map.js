### 解题思路

用map

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var majorityElement = function(nums) {
    if (nums.length === 0) return []
    const map = new Map()
    const target = nums.length / 3
    for (let i = 0; i < nums.length; i++) {
        if (map.has(nums[i])) {
            map.set(nums[i], map.get(nums[i]) + 1)
        } else {
            map.set(nums[i], 1)
        }
    }
    const res = []
    for (let key of map.keys()) {
        if (map.get(key) > target) {
            res.push(key)
        }
    }
    return res
};
```