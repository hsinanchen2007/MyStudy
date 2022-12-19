### 解题思路
三元运算符判断s1与s2是否等长，等长就将s1重复一次，判断s2是否在2s1中。

### 代码

```javascript
/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var isFlipedString = function(s1, s2) {
    return s1.length===s2.length?s1.repeat(2).includes(s2):false
};
```