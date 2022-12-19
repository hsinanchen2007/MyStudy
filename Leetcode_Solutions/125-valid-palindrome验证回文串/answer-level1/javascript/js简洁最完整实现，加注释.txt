```js
const isPalindrome = function(s) {
  // 去掉字母数字外其他符号，转换为小写
  s = s.replace(/\W|_/g, "").toLowerCase();
  let i = 0;
  // 遍历一半即可
  while (i < (s.length - 1) / 2) {
    if (s.charAt(i) !== s.charAt(s.length - 1 - i)) {
      return false;
    }
    i++;
  }
  return true;
};
```  
时间复杂度：$O(N)$ 
空间复杂度：$O(1)$   


更多JS题解：[github](https://github.com/zytjs/js-algorithm)