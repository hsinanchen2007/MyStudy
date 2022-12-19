![Snipaste_2020-04-02_17-00-31.png](https://pic.leetcode-cn.com/4473a4d02bf85904d9629bba54ce0b13c2efc14e050fa414841fc0d501ff7c40-Snipaste_2020-04-02_17-00-31.png)

### 解题思路
解法一:借助 parseInt(string, radix)，parseInt() 会尽可能把字符串转换成数字
解法二：正则表达式'/^[\+\-]?\d+/g'

### 代码
解法一：parseInt()
```javascript
var myAtoi = function (str) {
    const number = parseInt(str, 10);
    const Max = Math.pow(2, 31) - 1;
    const Min = Math.pow(-2, 31);
    
    // 无法转换的情况返回 0
    if (isNaN(number)) {
        return 0;
    }
    // 转换结果超出范围的情况
    if (number < Min || number > Max) {
        return number < 0 ? Min : Max;
    }
    return number;
};
```
解法二：正则表达式
```javascript
var myAtoi = function (str) {
    const input = str.trim();
    let reg = new RegExp(/^[\+\-]?\d+/g);
    if (!reg.test(input)) {
        return 0
    }
    return Math.max(Math.min(input.match(reg)[0], Math.pow(2, 31) - 1), Math.pow(-2, 31))
};
```
