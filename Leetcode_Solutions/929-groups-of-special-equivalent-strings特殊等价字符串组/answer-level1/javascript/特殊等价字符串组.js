```js
var numSpecialEquivGroups = function(A) {
    let set = new Set()
    for (let i = 0; i < A.length; i++) {
        let item = A[i];
        let odd = []
        let even = []
        for (let k = 0; k < item.length; k++) {
            if (k % 2 == 0) {
                odd.push(item[k]) 
            } else {
                even.push(item[k])
            }
        }
        set.add(odd.sort().join('') + even.sort().join(''))
    }
    return set.size
};
```
