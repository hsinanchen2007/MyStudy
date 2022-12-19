### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var compressString = function(S) {
  var arrS = S.split('');
  var number = 1;
  var resStr = '';
  for(var i = 0; i < arrS.length; i++) {
    if (arrS[i + 1] && (arrS[i + 1] === arrS[i])) {
      number = number + 1;
    } else {
      resStr = resStr + arrS[i] + number;
      number = 1;
    }
  }
  return resStr.length >= S.length ? S : resStr
};
```