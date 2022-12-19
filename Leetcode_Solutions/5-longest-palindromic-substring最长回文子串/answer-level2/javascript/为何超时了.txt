```js
var longestPalindrome = function (s = '') {
  const { length } = s;

  for (let len = length; len > 1; len--) {
    for (start = 0; start <= length - len; start++) {
      const str = s.substr(start, len);
      if (str === str.split('').reverse().join('')) {
        return str;
      }
    }
  }

  return s[0] || '';
};
```
这个复杂度应该是O(n^2)吧, 为何超时了