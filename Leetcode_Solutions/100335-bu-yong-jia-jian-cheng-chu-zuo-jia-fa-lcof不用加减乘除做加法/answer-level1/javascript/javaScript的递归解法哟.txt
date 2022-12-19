### 解题思路
啥也不说了 , 就抛出这个流弊的公式 , 可以想想这是为什么
计算a+b，等价于(a^b)**+**((a&b)<<1)。

### 代码

```javascript
/**
 * @param {number} a
 * @param {number} b
 * @return {number}
 */
var add = function(a, b) {
    if(a == 0) return b;
    if(b == 0) return a;
    return add(( a ^ b ),((a & b) << 1));
};
```