### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var compressString = function(S) {
  const reg = /([a-zA-Z])\1*/g;

  let o = '';
  while ((result = reg.exec(S)) !== null) {
    o += result[1] + result[0].length;
  }
  if (o.length >= S.length) return S;
  else return o;
};
```