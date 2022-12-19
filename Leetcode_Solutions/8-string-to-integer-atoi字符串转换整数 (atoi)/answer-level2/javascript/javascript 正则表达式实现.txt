重点审题：
1. 去掉字符串的开头空格
2. 判断首字母是否合法，若不合法，直接返回0
3. 设置数字的边界，为后边做判断
4. 正则匹配拿到匹配的值res
5. 根据res的范围结合题目要求给出返回值

```javascript []
var myAtoi = function(str) {
    str = str.replace(/(^\s*)/g, "");   // 去掉开头空格
    // 判断首字母是否合法以及  -+3 这样的字符串，可以在这一步判断第二个字母是否为数字
    if(isNaN(str[0]) && str[0]!=='-'&& str[0]!=='+' && !isNaN(str[1])) {
        return 0
    }
    // 定义最大值和最小值
    const max = Math.pow(2, 31) - 1;
    const min = Math.pow(2, 31) * - 1;
    // 正则表达式匹配正负整数
    const reg = /^([-|+])?\d+/;
    let res = 0
    if(reg.test(str)) {
        res = RegExp.lastMatch;
    }
    if(res < min) {
        return min
    }else if(res < max) {
        return res
    }else {
        return max
    }
};
```

