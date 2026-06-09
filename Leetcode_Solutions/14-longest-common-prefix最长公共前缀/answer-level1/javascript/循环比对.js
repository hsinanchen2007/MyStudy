### 解题思路

将第1个和第二个比对，得出最长公共后缀后，将此后缀与下一个比对，一直到最后一个或者到公共后缀为空字符串。

### 代码

```javascript
var longestCommonPrefix = function(strs) {
  if (strs.length == 0) {
    return ''
  }

  function getSame(a, b) {
    var min = Math.min(a.length, b.length)
    var sameCount = 0
    for (var i = 0; i <= min; i) {
      if (i == min || a[i] != b[i]) {
        sameCount = i
        break;
      } else {
        i++
      }
    }
    return a.substring(0, sameCount)
  }

  var result = '';
  var sameletter = strs[0]
  for (var m = 0; m < strs.length - 1; m++) {

    sameletter = getSame(sameletter, strs[m + 1])

  }
  return sameletter;
};
```