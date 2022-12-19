#### 官方题解借鉴桶排序的js实现

- 一直在纠结-0 === 0 为true这个问题，最后觉得只要向下取整其实也可以解决这个问题
- 不一定用map，用最简单的对象当然也行

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number} t
 * @return {boolean}
 */
var containsNearbyAlmostDuplicate = function(nums, k, t) {
    // 解决js中 -0 === 0 为true的问题
    function getId(x, w) {
        return Math.floor(x / w)
    }
    if (t < 0) return false
    const map = new Map()
    const w = t + 1
    for (let i = 0; i < nums.length; i++) {
        const m = getId(nums[i] ,w)
        if (map.has(m)) return true
        else if (map.has(+m + 1) && Math.abs(map.get(+m + 1) - nums[i]) < w) return true
        else if (map.has(+m - 1) && Math.abs(map.get(+m - 1) - nums[i]) < w) return true
        map.set(m, nums[i])
        if (i >= k) map.delete(getId(nums[i - k], w))
    }
    return false
};
```
