### 思路
1. 获取到两个字符串的最长值 max
2. 通过while的方法一直遍历到每一个字符的index；
3. 短的字符肯定会有一段为undefined，那么这时通过 undefined || 0的方式使其为0；
4. 由于是从最后一个开始计算，所以每次计算字符串的索引是 str.length - 1 - i;
5. 通过一个标志位判断是否进位，每次计算当前为的时候一定要加上标志位；
6. 最后如果标志位有值，那么就在最前面补1；
```javascript []
var addBinary = function(a, b) {
  let max = Math.max(a.length, b.length);
  let flag = 0;
  let result = '';
  let current = 0;
  let i = 0;
  while(i < max) {
    current = +(a[a.length - i - 1] || 0) + +(b[b.length - i - 1] || 0) + flag;
    flag = current / 2 >= 1?1:0;
    result = current % 2 + result;
    i++;
  }
  return flag?1+result:result;
};
```
