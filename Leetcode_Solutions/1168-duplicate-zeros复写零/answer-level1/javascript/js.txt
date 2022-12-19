倒着来处理


```
/**
 * @param {number[]} arr
 * @return {void} Do not return anything, modify arr in-place instead.
 */
var duplicateZeros = function(arr) {
    var s = arr.length
    while (s>=0) {
    if(arr[s] === 0){
      
      arr.splice(s,0,0)
      arr.pop()
    }
    s--
   }
};
```
