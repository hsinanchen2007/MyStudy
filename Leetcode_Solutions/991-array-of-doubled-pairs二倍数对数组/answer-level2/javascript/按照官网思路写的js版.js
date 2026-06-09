```
var canReorderDoubled = function (A) {
    var cntMap = new Map()
    for (var i = 0; i < A.length; i++) {
        cntMap.set(A[i], cntMap.get(A[i]) ? cntMap.get(A[i]) + 1 : 1)
    }
    var B = [...A]
    B.sort(function (a, b) { return Math.abs(a) - Math.abs(b) })
    for (var i = 0; i < B.length; i++) {
        var x = B[i]
        if (cntMap.get(x) == 0) continue
        if (cntMap.get(2 * x) == 0 || cntMap.get(2 * x) == undefined) return false
        cntMap.set(x, cntMap.get(x) - 1)
        cntMap.set(2 * x, cntMap.get(2 * x) - 1)
    }
    return true
};
```
