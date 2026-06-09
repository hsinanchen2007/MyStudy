js版本：
![1569497791662.jpg](https://pic.leetcode-cn.com/40ecec8b0045ef81e50c7c0841a825b2e66ac20c0f8a1341e9a8a83a08569fdb-1569497791662.jpg)

```
代码
```
var countBinarySubstrings = function(s) {
  const len = s.length;

  let n = 0,
    pre = 0,
    current = 1;
  for (let i = 0; i < len; i++) {
    if (s[i] === s[i + 1]) {
      current++;
    } else {
        //当发现第三次不同时，前两组中最小的个数就是匹配出来的组数，比如00011,就有2组，一次类推
      if (pre > 0) {
        n += Math.min(pre, current);
      }
      pre = current;

      current = 1;
    }
  }
  return n;
};
···