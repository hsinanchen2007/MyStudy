```
var n = 25
var m
var arr = []
arr[0] = 0
arr[1] = 1
arr[2] = 1
arr[3] = 2
switch(n){
    case 0:
        return 0
        break
    case 1:
        return 1
        break
    case 2:
        return 1
        break
}
for(var i=3; i<=n; i++){
    arr[i] = arr[i-1]+arr[i-2]+arr[i-3]
    m = arr[i]
}    
console.log(m)
```
朴素的for循环解法，有点low，内存-js-100%。
