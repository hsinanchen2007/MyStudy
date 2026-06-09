```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var containsNearbyDuplicate = function(nums, k) {
    let minIndices = new Map()
    let distance = Number.MAX_SAFE_INTEGER
    const length = nums.length
    for(let i = 0; i < length; i++) {
        const current = nums[i]
        if(minIndices.has(current)) {
            let d = i - minIndices.get(current)
            distance = Math.min(distance, d)
        }
        minIndices.set(current, i)
    }
    return distance <= k
};
```
`distance`是两个相同数距离的最小值，初始化为最大，然后遍历数组，如果在`set`里面找到数，就将`Math.min(distance, i - set.get(current))`存入`distance`，并将`set`中的下标更换。