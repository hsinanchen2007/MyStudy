```

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var isPossibleDivide = function(nums, k) {
    if(nums.length % k !== 0) return false
    nums.sort((a, b) => a - b)
    const map = new Map()
    for(let i = 0; i < nums.length;i++) {
        if(map.has(nums[i])) {
            map.set(nums[i], map.get(nums[i]) + 1)
        } else map.set(nums[i], 1)
    }
    let len = 0
    while(len < nums.length) {
        let temp = nums.find(v => map.has(v))
        if(temp === undefined) return false
        let i = 0
        temp -= 1
        for(;i < k;i++) {
            temp = temp + 1
            const count = map.get(temp)
            if(count === undefined) return false
            if(count === 1) {
                map.delete(temp)
            } else map.set(temp, count  - 1)
        }
        len += k
    }
    return true
};
```
