### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} a
 * @param {string} b
 * @return {number}
 */
var findLUSlength = function (a, b) {
  let alen = a.length
  let blen = b.length
  if(a === b){
    return -1
  }
    return alen > blen ? alen : blen
  };
```