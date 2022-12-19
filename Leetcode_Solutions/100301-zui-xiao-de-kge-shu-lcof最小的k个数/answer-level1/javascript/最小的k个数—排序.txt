先排序，在取前k个数
```
var getLeastNumbers = function(arr, k) {
    arr.sort(function(a,b){
        return a-b
    })
    // console.log(arr)
    return arr.slice(0,k)
};
```
