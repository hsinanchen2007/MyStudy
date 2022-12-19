### 代码

```javascript
var intersect = function(nums1, nums2) {
    nums1.sort((a, b) => a - b)
    nums2.sort((a, b) => a - b)
    let pointer1 = 0
    let pointer2 = 0
    const res = []
    while (pointer1 < nums1.length && pointer2 < nums2.length) {
        if (nums1[pointer1] === nums2[pointer2]) {
            res.push(nums1[pointer1])
            pointer1++
            pointer2++
        } else if (nums1[pointer1] < nums2[pointer2]) {
            pointer1++
        } else {
            pointer2++
        }
    }
    return res
};
```
时间复杂度：O(nlogn)
空间复杂度：O(Min(n, m))