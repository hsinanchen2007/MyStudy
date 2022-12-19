^开头
\s* 匹配0/多个空字符
[+|-]? 一个或多个字符
\d+ 1个或多个数字

最后匹配下边界大小，代码如下
```
    var myAtoi = function(str) {
        let reg = new RegExp(/^\s*[+|-]?\d+/g);

        if(reg.test(str) == false){return 0}
        let num = str.match(reg)[0];

        return Math.max( Math.min(num, Math.pow(2, 31) - 1), Math.pow(-2, 31));
    };
```

    