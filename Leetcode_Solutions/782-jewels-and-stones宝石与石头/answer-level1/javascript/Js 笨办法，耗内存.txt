### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} J
 * @param {string} S
 * @return {number}
 */
var numJewelsInStones = function (J, S) {
  let arr_J = J.split('');
  let arr_S = S.split('');
  let total = 0;
  for (let j = 0; j < J.length; j++) {
    for (let s = 0; s < S.length; s++) {
      if (arr_J[j] === arr_S[s]) {
        total++;
      }
    }
  }
  return total
};
```