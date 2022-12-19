![image.png](https://pic.leetcode-cn.com/d55bce6dda5b5d38fe6227dd763e475a4f65de3f912e0e1b47f5b2b29f2e7106-image.png)

### 解题思路
大写：65 。。。
小写：97 。。。
考察 String.fromCharCode 和 charCodeAt 的使用，以及大小写字母 Ascll 表中的关系

### 代码

```javascript
/**
 * @param {string} str
 * @return {string}
 */
var toLowerCase = function(str) {
  let ans = '',
      upperLetters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ';
  
  for (let i = 0, len = str.length; i < len; i++) {
    if (upperLetters.indexOf( str[i] ) > -1) {
      let n = String.fromCharCode( str[i].charCodeAt() + 32 );
      ans += n;
    } else {
      ans += str[i];
    }
  }
  
  return ans;
};
```