```
/**
 * 学习官方单调栈javascript解决方法
 * O(m + n)
 */
var nextGreaterElement = function(nums1, nums2) {
    const map = {}
    const stack = []
    for (let i = 0; i < nums2.length; i++) {
        while (stack.length && stack[stack.length - 1] < nums2[i]) {
            const top = stack.pop()
            map[top] = nums2[i]
        }
        stack.push(nums2[i])
    }
    stack.forEach(item => {
        map[item] = -1
    })
    console.log(stack)
    console.log(map)
    const res = []
    nums1.forEach(item => {
        res.push(map[item])
    })
    return res
};
```

```

/**
 * 双重循环
 * O(n ^ 2)
 */
var nextGreaterElement = function(nums1, nums2) {
    const array = []
    nums1.forEach(item => {
        const idx = nums2.indexOf(item)
        let res = -1
        if (idx >= 0) {
            for (let i = idx + 1; i < nums2.length; i++) {
                console.log(nums2[i])
                if (nums2[i] > item) {
                    res = nums2[i]
                    break
                }
            }
        }
        array.push(res)
    })
    return array
};

```
