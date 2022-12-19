### 解题思路
![image.png](https://pic.leetcode-cn.com/391addabe0732736dff69794bfbef3cfba717e46d6878634032d4a0e2ef5ca9d-image.png)

利用两数组间最大公约数， 递增判断


### 代码

```javascript
/**
 * @param {string} str1
 * @param {string} str2
 * @return {string}
 */
var gcdOfStrings = function(str1, str2) {
      if (!str1 || !str2) return '';
      if (str2 === str1) return str1;
      let res = '', temp = ''
      function gyy(m, n) {
        var r = m % n;
        m = n;
        n = r;
        if (r == 0) {
          return m;
        } else {
          return gyy(m, n);
        }
      }
      const gcd = gyy(str1.length, str2.length);
      for (let i = 0; i < gcd; i++) {
        temp += str2[i];
        if (str1.length % (i+1) === 0) {
          if (temp.repeat(str1.length / (i+1)) === str1) {
            res = temp;
          }
        }
      }
      return res;
    };
```