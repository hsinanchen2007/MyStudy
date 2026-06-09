### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
 let map = {
    I: 1,
    V: 5,
    X: 10,
    L: 50,
    C: 100,
    D: 500,
    M: 1000
  };
  let arr = s.split("");
  let temp = [];
  for (let i = 0; i < arr.length; i++) {
    if (map[arr[i]] >= map[arr[i + 1]]) {
      temp.push(map[arr[i]]);
    } else {
      if (i == arr.length - 1) {
        temp.push(map[arr[i]]);
      } else temp.push(map[arr[i]] * -1);
    }
  }
  return temp.reduce((a, b) => a + b);
};
```