### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} N
 * @return {number}
 */
var fib = function(N) {
  let current =0;
  let pre = 1;
  let next = 1;
  if(N<=1) {
    return N;
  }
  if(N===2) {
    return 1;
  }
  for(let i=3;i<=N;i++){
    current = pre+next;
    pre = next;
    next = current;
  }
  return current;
};
```