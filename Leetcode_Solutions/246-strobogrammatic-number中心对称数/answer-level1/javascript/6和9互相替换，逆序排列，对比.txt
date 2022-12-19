`6`和`9`相互替换掉，然后逆序排列和原字符串对比。

但不能有`0`,`1`,`6`,`8`,`9`之外的数字。
```
var isStrobogrammatic = function(num) {
  const tmp = num.split('');
  if(tmp.some(x => !['0','1','6', '8','9'].includes(x))) return false;
  return tmp.map(x => x==='6' ? '9' : x==='9' ? '6' : x).reverse().join('') === num;
};
```
