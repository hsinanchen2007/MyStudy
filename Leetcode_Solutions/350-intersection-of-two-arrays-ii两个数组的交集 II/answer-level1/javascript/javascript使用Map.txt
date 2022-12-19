### 解题思路
使用Map

### 代码

```javascript
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersect = function(nums1, nums2) {
    if (!nums1.length || !nums2.length) {
        return []
    }
    const map1 = new Map()
    const res = []
    nums1.forEach(num => {
        if (map1.has(num)) {
            map1.set(num, map1.get(num) + 1)
        } else {
            map1.set(num, 1)
        }
    })
    nums2.forEach(num => {
        if (map1.has(num) && map1.get(num) > 0) {
            res.push(num)
            map1.set(num, map1.get(num) - 1)
        }
    })
    return res
};
```