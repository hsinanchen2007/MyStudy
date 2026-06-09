![image.png](https://pic.leetcode-cn.com/58688089e2a16ac7bcdfba44f337094a83564d8616441390f4c08779a12284a6-image.png)

### 解题思路
```js
  学习一下欧几里得算法 gcd 
  const gcd = (a, b) => return b === 0 ? a : gcd( b, a % b )
```

### 代码

```javascript
/**
 * @param {string} str1
 * @param {string} str2
 * @return {string}
 */

var gcdOfStrings = function(str1, str2) {
  const gcd = (a, b) => {
    if (b === 0) return a;
    return gcd(b, a % b);
  }
  
  if (str1 + str2 !== str2 + str1) return '';
  
  return str1.substring(0, gcd(str1.length, str2.length));
};
```