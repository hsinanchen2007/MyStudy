```
var findRepeatNumber = function (nums) {
    let map = new Map(), ans

    for (let i = 0; i < nums.length; i++) {
        let num = nums[i]
        map.set(num, map.has(num) ? map.get(num) + 1 : 1)
        if (map.get(num) > 1) {
            ans = num
            break
        }
    }
    return ans
};
```
