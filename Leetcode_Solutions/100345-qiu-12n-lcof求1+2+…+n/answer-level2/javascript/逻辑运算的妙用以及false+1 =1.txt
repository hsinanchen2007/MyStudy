### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var sumNums = function(n) {
  if(n===0) {
      return 0;
  }
  return (n>0)&&(sumNums(n-1)+n);
};
```