```js
var findShortestSubArray = function(nums) {
    let map = new Map();
    let len = nums.length;
    for(let item of nums) {
        if (!map.has(item)) {
            map.set(item, 1)
        } else {
            map.set(item, map.get(item)+1)
        }
    }
    let maxCount = Math.max.apply(Math, [...map.values()]);
    let maxVals = [];
    for(let [key, val] of map) {
        if(val === maxCount) {
            maxVals.push(key)
        }
    }
    let min = Number.MAX_SAFE_INTEGER;
    for (let item of maxVals) {
        let start = nums.indexOf(item);
        let end = nums.lastIndexOf(item) + 1;
        if (end - start < min) {
            min = end - start;
        }
    }
    return min;
};
```