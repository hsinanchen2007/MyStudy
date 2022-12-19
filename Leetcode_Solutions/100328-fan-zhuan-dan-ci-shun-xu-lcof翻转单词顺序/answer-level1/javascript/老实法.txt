做个老实人

```javascript
var reverseWords = function(s) {
  let str = '';
  for (let i = 0; i < s.length;) {
    if (s[ i ] === ' ') {
      i++;
      continue;
    };
    let currStr = '';
    let j = i;
    while(j < s.length) {
      if (s[ j ] === ' ') break;
      currStr += s[ j ];
      j++
    }
    i = j + 1;
    currStr = str ? currStr + ' ' : currStr;
    str = currStr + str;
  }
  return str;
};
```