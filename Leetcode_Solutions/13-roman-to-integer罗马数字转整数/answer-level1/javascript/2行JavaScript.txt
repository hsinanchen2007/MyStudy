将每个字符转为整数，然后如果当前位小于下一位，再将其改为负数，最后累加。

```javascript
const romanToInt = function(s) {
  const m = { 'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000 }
  return s.split('').reduce((p, c, i, a) => p + (m[c] < m[a[i + 1]] ? -m[c] : m[c]), 0)
};
```