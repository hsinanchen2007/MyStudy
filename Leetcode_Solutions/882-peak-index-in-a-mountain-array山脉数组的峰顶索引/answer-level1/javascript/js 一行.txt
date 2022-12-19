```
var peakIndexInMountainArray = function (A) {
    return A.indexOf(A.reduce((prev, curr) => Math.max(prev, curr), 0))
};
```
