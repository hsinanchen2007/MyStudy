### 解题思路
先列出所有的罗马字母对应的数字的映射表
然后考虑特殊的罗马字符情况（会返回负值）

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
  let totalMap = {
     I: 1,
     V: 5,
     X: 10,
     L: 50,
     C: 100,
     D: 500,
     M: 1000
  }, source = s.split(''), result = 0 
  function getValue (left, right) {
    if (['IV','IX','XL','XC','CD','CM'].includes(left + right)) {
      return -1 * totalMap[left]
    }
      return totalMap[left]
  }
  for (let i = 0; i < source.length; i++) {
    result += getValue(source[i], source[i+1] || '')
  }
  return result
};
```