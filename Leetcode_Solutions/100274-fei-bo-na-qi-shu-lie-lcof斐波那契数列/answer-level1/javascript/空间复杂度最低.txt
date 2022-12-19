### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var fib = function(n) {
  let pre = 0;
  let next = 1;
  let current = 0;
  for(let i=0;i<n;i++){
      current = (pre + next) % 1000000007;
      pre = next;
      next = current;
  }
  return pre;
};
```