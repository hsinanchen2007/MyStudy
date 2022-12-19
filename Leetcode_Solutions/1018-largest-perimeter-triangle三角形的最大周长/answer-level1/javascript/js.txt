来自官方题解的思路
但执行用时152 ms
内存消耗38.1 MB

```javascript
var largestPerimeter = function(A) {
    A.sort((a,b) => a - b);
    // console.log(A);
    for(let i = A.length-3; i >= 0; i--){
        if(A[i] + A[i+1] > A[i+2])
            return A[i]+A[i+1]+A[i+2];
    }
    return 0;
}
```
