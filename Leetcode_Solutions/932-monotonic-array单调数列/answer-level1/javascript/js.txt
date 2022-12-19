### 解题思路
定义变量regular保存 规律，循环判断当规律改变时返回false

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {boolean}
 */
var isMonotonic = function(A) {
  if(A.length === 1){
    return true
  }
  let regular
  for (let i = 0; i < A.length; i++) {
    if(A[i]<A[i+1]){
      if(regular===1){
        return false
      }else{
        regular = -1
      }
    }else if(A[i]>A[i+1]){
      if(regular===-1){
        return false
      }else {
        regular = 1
      }
    }else {
    }
  }
  return true
};
```