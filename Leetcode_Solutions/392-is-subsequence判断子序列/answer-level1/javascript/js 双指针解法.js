1. 判断字符长度，s不能长于t，s为空时，一定为子序列;
2. 逐个遍历s字符串，用s的每个字符串与t中的字符进行对比；
3. 若相等，则跳出t字符串的循环，每次循环t中扫描步长加一；
4. 直到扫描完s字符串，并且出现匹配项,判定s为t的子序列；其余情况皆为false;
```javascript []
var isSubsequence = function(s, t) {
  var sLen = s.length;
  var tLen = t.length;
  if (sLen > tLen) {
    return false;
  }
  if (sLen === 0) {
    return true;
  }
  var step = 0;
  for (var i = 0; i < sLen; i++) {
    while (step < tLen) {
      if (t[step] === s[i]) {
        step++;
        if (i === sLen - 1) {
          return true;
        }
        break;
      }
      step++;
    }
  }
  return false;
};
```