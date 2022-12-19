1. 直接暴力双重循环查找
```javascript
var intersect = function (nums1, nums2) {
    let res = []
    for (let i = 0; i < nums1.length; i++) {
        for (let j = 0; j < nums2.length; j++) {
            if (nums1[i] === nums2[j]) {
                res.push(nums1[i])
                nums2.splice(j, 1)
                break
            }
        }
    }
    return res
};
```

2.  Hash 表存储nums1的的所有数字出现次数，再遍历一遍nums2，如果从map中取到了值，便将其出现次数减1并记录下来，注意将较小数组存入 map 中可以节约 map 空间
```javascript
var intersect = function (nums1, nums2) {
    let map = new Map()

    if (nums2.length > nums1.length) {
        let tmp = nums2
        nums2 = nums1
        nums1 = tmp
    }

    for (let i = 0; i < nums1.length; i++) {
        let count = map.get(nums1[i])
        if (count === undefined) {
            map.set(nums1[i], 1)
        } else {
            map.set(nums1[i], count + 1)
        }
    }

    let res = []
    for (let i = 0; i < nums2.length; i++) {
        let count = map.get(nums2[i]);
        if (count !== undefined && count !== 0) {
            res.push(nums2[i])
            map.set(nums2[i], count - 1)
        }
    }
    return res
};
```

3. 双指针指向两个数组，如果两者所指的元素大小相同，则记录下该元素，并将双指针都前进一位，否则比较当前元素大小，比较小的那一个元素，指针前进一位
```
var intersect = function (nums1, nums2) {
    let p1 = 0
    let p2 = 0
    let res = []

    nums1.sort((a, b) => a - b)
    nums2.sort((a, b) => a - b)

    while (p1 < nums1.length && p2 < nums2.length) {
        if (nums1[p1] === nums2[p2]) {
            res.push(nums1[p1])
            p1++
            p2++
        } else if (nums1[p1] > nums2[p2]) {
            p2++
        } else {
            p1++
        }
    }
    return res
};
```