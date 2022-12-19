### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} n
 * @return {number[]}
 */
var printNumbers = function(n) {
  let str = '';
  let arr = [];
  if(n<1) {
    return [];
  }
  for(let i=0;i<n;i++) {
    str +='9';
  }
  for(let j=1;j<=parseInt(str);j++){
      arr.push(j);
  }
  return arr;
};
```