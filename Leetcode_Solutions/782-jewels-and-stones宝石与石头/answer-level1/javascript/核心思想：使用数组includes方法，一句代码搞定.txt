一句代码搞定。参数转化为两个数组，遍历S过滤出包含于宝石数组的部分获得一个新数组，这个数组的长度就是宝石个数。

```javascript []
var numJewelsInStones = function(J, S) {
    return S.split('').filter(v => J.split('').includes(v)).length
    
};
```
