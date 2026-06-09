解题思路很简单，回文无非就两种情况，一种是aba型，一种是abba型。
遍历字符串，第n个字符跟前后字符相比较，如果是aba型，就判断n-1位是否等于n+1位,如果相等，再判断n-2位是否等于n+2位，以此类推。如果是abba型，就判断n位是否等于n+1位,n-1位是否等于n+2位...。

代码如下
```
var longestPalindrome = function(s) {
  let len = s.length;
  let palindromeText = s.charAt(0);
  let range = 1;
  if (len <= 1) {
    return s;
  }
  for (let i = 0; i < len; i++) {
    range = 1;
    while (i>0 && (i - range) >= 0 && (i + range) < len && s.charAt(i - range) === s.charAt(i + range)) {
      if (palindromeText.length < 2 * range + 1) {
        palindromeText = s.substr(i - range, 2 * range + 1);
      }
      range++;
    }
    range = 1;
    while ((i - range + 1) >= 0 && (i + range) <= len && (s.charAt(i - range + 1)) === s.charAt(i + range)) {
      if (palindromeText.length < 2 * range) {
        palindromeText = s.substr(i - range + 1, 2 * range);
      }
      range++;
    }
  }
  return palindromeText;
};
```
