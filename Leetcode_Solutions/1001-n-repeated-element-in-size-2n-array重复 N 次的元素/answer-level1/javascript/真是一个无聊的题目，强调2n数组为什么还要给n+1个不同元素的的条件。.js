本来以为是个求中位数的题目
```
var repeatedNTimes = function(A) {
    A.sort((a, b) => a - b);
    let length = A.length;
    if(A[0] == A[length / 2 - 1]){
        return A[0]
    }
    if(A[length / 2] == A[length - 1]){
        return A[length - 1];
    }
    return A[length / 2];
}
```

结果就是个求个重复值得题目
```
var repeatedNTimes = function(A) {
    let set = new Set();
    for(let e of A){
        if(!set.has(e)){
            set.add(e);
        }else{
            return e;
        }
    }
}
```