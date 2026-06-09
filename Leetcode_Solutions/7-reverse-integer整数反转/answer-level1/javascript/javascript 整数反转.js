思路1:
    每次按十位求余，然后乘十到输出上。
    时间：124ms 内存： 35.5****
```
var reverse = function (x) {
    x = parseInt(x);
    var back = 0;
    while (x) {
        back = back * 10 + x % 10;
        x = parseInt(x / 10);
    }
    if (back > 2147483647 || back < -2147483648) {
        return 0;
    }
    return back;
}
```


思路2:
    这个思路可以说是非常的直观了，就是字符串处理。

    这个方法上我尝试了一下优化，限于个人水平，如下：

    A：拆分了正负处理
        时间：112ms 内存： 35.7

    B：原代码
        时间：104ms 内存： 36.2
     
```
var reverse = function (x) {
    x = x.toString();
    var bool = true;
    if (x[0] == '-') {
        var back = "-";
        x = x.substr(1, x.length)
    } else {
        var back = '';
    }
    for (var i = x.length - 1; i >= 0; i--) {
        if (bool && x[i] == '0') {} else {
            bool = false;
            back += x[i];
        }
    }
    if (back > 2147483647 || back < -2147483648) {
        return 0;
    }
    return back;
};
```
