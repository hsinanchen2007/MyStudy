```javascript []
var peakIndexInMountainArray = function (A) {
    let max = Math.max.apply(null, A)
    for(let i = 0; i < A.length; i++) {
        if (A[i] === max) {
            return i
        }
    }
};
```
