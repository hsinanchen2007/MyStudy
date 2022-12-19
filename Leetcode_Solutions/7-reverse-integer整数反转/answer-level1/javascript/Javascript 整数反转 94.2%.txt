解（伪）：
> 使用`while`循环对`x`进行求余将每一位分离。

```js
var reverse = function (x) {
    var i = 0;
    var re = 0;
    while (parseInt(x / 10)) {
        re = 10 * re + x - 10 * parseInt(x / 10);
        x = parseInt(x / 10);
        i++;
    }
    re = 10 * re + x;
    if (re > 2147483647 || re < -2147483648) return 0;
    return re
};
```

解（真）：
> 上面的解忽略了题目中`环境只能存储得下 32 位的有符号整数`这一限制，虽然最后对`re`进行了范围判断，但是显然在`re`已溢出的情况下范围判断是失效的。
>
>因此，定位到产生溢出的语句`re = 10 * re + x;`，发生溢出有两种情况：
* `10 * re`时溢出
* `+ x`时溢出，当`10 * re = INT_MIN/10 或 INT_MAX/10`且`x > 7 或 x < -8`发生

```js
var reverse = function (x) {
    var re = 0;
    while (parseInt(x / 10)) {
        re = 10 * re + x - 10 * parseInt(x / 10);
        x = parseInt(x / 10);
    }
    if (re > 214748364 || re < -214748364) return 0;
    if ((re == 214748364 && x > 7) || (re == 214748364 && x < -8)) return 0;
    re = 10 * re + x;
    return re
};
```

