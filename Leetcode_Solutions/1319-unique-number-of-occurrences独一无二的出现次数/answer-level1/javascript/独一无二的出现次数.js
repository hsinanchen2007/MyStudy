```javascript
var uniqueOccurrences = function(arr) {
    let map = new Map()
    arr.forEach((item) => {
        if (!map.has(item)) {
            map.set(item, 1)
        } else {
            map.set(item, map.get(item) + 1)
        }
    })
    return map.size == new Set([...map.values()]).size
};
```