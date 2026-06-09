```javascript
var lengthOfLongestSubstring = function(s) {
  let num = 0,res = 0;
  let m = '';
  for (n of s) {
    if (m.indexOf(n) == -1) {
      m += n;
      num++;
      res = res < num ? num: res;
    } else {
      m += n;
      m = m.slice(m.indexOf(n)+1);
      num = m.length;
    }
  }
  return res;
};
```

![2871571817488_.pic.jpg](https://pic.leetcode-cn.com/c9fa3e36d648a84c203a89d80fca13a7a3ddd3c6b460b89bdcf59874d5296d9f-2871571817488_.pic.jpg)

