#### 思路
将数字转成字符串，然后反转求值，判断边界即可。
#### 代码
```
var reverse = function(x) {
    if (x === 0) {
        return 0;
    }
    // 保存正负
    let mark = x > 0 ? 1 : -1;
    // 转成字符串
    x = Math.abs(x) + '';
    let temp = 0;
    for (let i = x.length - 1; i >= 0; i--) {
        temp += x[i] * 10 ** i;
    }
    // 判断边界
    if (temp > 2 ** 31 -1 || temp < (-2) ** 31 -1) {
        return 0;
    }
    return temp * mark;
};
```
