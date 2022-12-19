```javascript
var climbStairs = function(n) {

let arr=[0,1,2]
function fibonaci(n){
if(arr[n]!=null) return arr[n]
return (arr[n] = fibonaci(n-1)+fibonaci(n-2))
}
fibonaci(n)
return arr[n]
};
```
代码源自于《学习javascript版数据结构与算法》