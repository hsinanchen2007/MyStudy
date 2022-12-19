### 解题思路
转换成字符串进行正则匹配

### 代码

```javascript
/**
 * @param {character[][]} board
 * @return {number}
 */
var numRookCaptures = function(board) {
  const rowStr = board.filter(arr=>arr.indexOf('R')!==-1)[0].join('');
  const ind = rowStr.indexOf('R');
  const colStr = board.map(arr=>arr[ind]).join('');
  const reg1 = /p\.*R/;
  const reg2 = /R\.*p/;
  let i = 0;
  if(reg1.test(rowStr)) i += 1;
  if(reg2.test(rowStr)) i += 1;
  if(reg1.test(colStr)) i += 1;
  if(reg2.test(colStr)) i += 1;

  return i;
}
```