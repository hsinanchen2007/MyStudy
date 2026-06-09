### 解题思路
filter  /  includes

### 代码

```javascript
/**
 * @param {string} J
 * @param {string} S
 * @return {number}
 */
var numJewelsInStones = function (J, S) {
  return S.split('').filter(value => J.split('').includes(value)).length
};
```