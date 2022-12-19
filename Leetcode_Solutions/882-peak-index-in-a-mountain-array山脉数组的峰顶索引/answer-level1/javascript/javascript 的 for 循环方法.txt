```js
/**
 * @param {number[]} A
 * @return {number}
 */
var peakIndexInMountainArray = function(A) {
  let n = 0
  for(i=0;A[i]<A[i+1];i++){
    n = i
  }
// 因为找到最大的A[i]项的i值为for循环的条件语句中的值，
// 需将得到的循环语句中的i值加上1
  return n+1
};
```
