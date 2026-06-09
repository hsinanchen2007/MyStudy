```
var search = function (nums, target) {
    let map = new Map()
    nums.forEach((num, i) => {
        if (num === target) {
            map.set(num, map.has(num) ? map.get(num) + 1 : 1)
        }
    })
    return map.get(target) || 0
};
```
