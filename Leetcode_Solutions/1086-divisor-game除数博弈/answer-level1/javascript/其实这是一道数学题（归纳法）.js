奇数赢，证明如下：
>
    假设当前Alice回合，则：
    a. 如果N = 1，则输；
    b. 如果N = 2，则赢；
    c. 如果N = 3，则输；
    d. 如果N = 4，则赢；
    ...
    利用数学归纳法，如果N是奇数，则输；反之赢。

js代码
```js
/**
 * @param {number} N
 * @return {boolean}
 */
var divisorGame = function(N) {
    return !(N&1);
};
```

