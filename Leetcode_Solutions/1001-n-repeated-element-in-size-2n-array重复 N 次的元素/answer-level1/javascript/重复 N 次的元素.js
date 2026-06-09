```
var repeatedNTimes = function(A) {
    let set = new Set();
    for (let item of A) {
        if(!set.has(item)) {
            set.add(item)
        } else {
            return item
        }
    }
};
```
