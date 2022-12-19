```js
var reverse = function(x) {
    var sign = Math.sign(x);
    var rX = parseInt(x.toString().split("").reverse().join(""));
    var result = sign * rX;
    var min = - Math.pow(2, 31);
    var max = Math.pow(2, 31) -1;
    if(rX<min || rX>max) return 0;
    return result;
};
```

假设传入的整数为x。

1. 存储符号 Math.sign(x)
2. 反转数字
    1. 转换为string `x.toString()`
    2. 拆分为char数组 `x.toString().split("")`
    3. 反转数组并拼接 `x.toString().split("").reverse().join()`
    4. 转换为number `parseInt(x.toString().split("").reverse().join())`
3. 反转后数字溢出过滤 `- Math.pow(2, 31)  Math.pow(2, 31) -1`
4. 符号与数字相乘并返回

tips：
- 2.2 str.split("")？
str.split([separator[, limit]]),If separator is an empty string (""), str is converted to an array of each of its UTF-16 "characters".
- 2.3 arr.join()？
arr.join([separator]) If separator is an empty string, all elements are joined without any characters in between them.