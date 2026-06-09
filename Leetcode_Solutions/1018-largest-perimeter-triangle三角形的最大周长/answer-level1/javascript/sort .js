三角形的满足条件：a≤b≤c，两边之和大于第三遍
数组排序 从小到大排序，然后取最后三个，不满足递减
```
var largestPerimeter = function(A) {
    A.sort(function(a,b){return a-b})
    for (var i = A.length - 3; i >= 0; --i)
        if (A[i] + A[i+1] > A[i+2])
            return A[i] + A[i+1] + A[i+2];
    return 0;
};
```
