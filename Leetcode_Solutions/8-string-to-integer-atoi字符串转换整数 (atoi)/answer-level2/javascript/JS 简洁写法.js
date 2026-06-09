```JavaScript
const myAtoi = function(str) {
  // 提取需要的字符
  const result = str.trim().match(/^(-|\+)?\d+/g);
  return result
    ? Math.max(Math.min(Number(result[0]), 2 ** 31 - 1), -(2 ** 31))
    : 0;
};
```
说明：  
1. 使用正则提取满足条件的字符，`/^(-|\+)?\d+/g`，`(-|\+)?`表示第一位是-或+或都不是，`\d+`表示匹配多个数字。  
2. Math.max(Math.min(Number(result[0]), 2 ** 31 - 1), -(2 ** 31))是`- 2 ** 31 < num < 2 ** 31 - 1`的js写法，保证不超出范围。

不用正则也很简单实现，就是看起来比较繁琐。

GitHub求star！！[GitHub美女地址](https://github.com/zytjs/js-algorithm)