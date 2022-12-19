这是用来跑的代码我压缩成一行了，我发现一行跑的还真是快一点，152 ms
```javascript
var romanToInt = function (s, n = 0) { let [m, obj] = [s.length, { 'IV': 4, 'IX': 9, 'XL': 40, 'XC': 90, 'CD': 400, 'CM': 900, 'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000, }]; for (let i = 0; i < m; i++) { let [v1, v2] = [s[i], s[i - 0 + 1]]; n += v2 && obj.hasOwnProperty(v1 + v2) ? (() => { i++; return obj[v1 + v2]; })() : obj[v1]; } return n; };
```
这是格式化的代码 156->164->176->192 ,我不是很明白为什么同样的代码每隔2分钟刷新越来越慢
```javascript
var romanToInt = function (s, n = 0) {
    let [m, obj] = [s.length, {
        'IV': 4, 'IX': 9, 'XL': 40, 'XC': 90, 'CD': 400, 'CM': 900,
        'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000,
    }];
    // 因为需要纠正 key 所以用的 for ; ; ,大佬可以试试 map() + for in
    for (let i = 0; i < m; i++) {
        // 取 key，key + 1 字符
        let [v1, v2] = [s[i], s[i - 0 + 1]];
        // 判断是双字符数还是单字符数
        n += v2 && obj.hasOwnProperty(v1 + v2) ? (() => {
            // 双字符 key + 1 纠正 循环 ，返回 数字
            i++; return obj[v1 + v2];
        })() : obj[v1]; // 单字符不需要纠正 
    }
    return n;
};
```