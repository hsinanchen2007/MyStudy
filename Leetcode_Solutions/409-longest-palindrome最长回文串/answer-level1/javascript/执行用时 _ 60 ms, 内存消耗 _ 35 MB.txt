### 解题思路
此处撰写解题思路
一次循环，使用map记录每个字符的统计计数，出现偶数次可构成回文，回文长度+2。最后如果回文长度不等于字符长度，可从剩余字符中取出一个字符填在中间依然可构成回文，所以最大长度+1。
### 代码

```javascript
var longestPalindrome = function(s) {
  const map = new Map();
  const len = s.length;
  let sum = 0;
  for (let i=0; i<len; i+=1) {
    const c = s[i];
    const num = map.get(c) || 0;
    if (num % 2 === 1) {
      sum += 2;
    }
    map.set(c, num + 1);
  }
  return len===sum ? sum : sum+1;
};
```