
从代码精炼角度出发，练习 ECMAScript 6 语法的特性

```javascript []
var numJewelsInStones = function(J, S) {
    return [...S].filter(item => J.includes(item)).length
};
```