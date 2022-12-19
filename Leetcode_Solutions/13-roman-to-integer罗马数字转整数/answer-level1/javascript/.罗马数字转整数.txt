### 解题思路
简单理解使用map映射，取出最大罗马树，跟后一个比较大于的话就减去，小于的话就加上

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
  const maps = {
    I: 1,
    V: 5,
    X: 10,
    L: 50,
    C: 100,
    D: 500,
    M: 1000
  };
  let res = 0;
  let pre = maps[s[0]];
  for (let i = 1; i < s.length; i++) {
    const value = maps[s[i]];
    if (value > pre) {
      res -= pre;
    } else {
      res += pre;
    }
    pre = value;
  }
  res += pre;
  return res;
};
```