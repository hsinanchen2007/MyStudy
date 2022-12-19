### 解题思路

没看答案一段操作觉得自己就是傻逼。。。。。。大家不要学我。其实只要通过parseInt()就可以直接得出··我还在一顿if else真是耻辱。

### 代码

```javascript
/**
 * @param {string} str
 * @return {number}
 */
var myAtoi = function (str) {
    const numreg = /^[0-9]*$/

    const num = str.trim()
    const result = parseInt(str) || 0


    if (isNaN(result)) {
        return 0;
    }
    if (num[0] == '-') {
        const min = Math.pow(-2, 31)
        return result < min ? min : result
    }
    else if (numreg.test(num[0]) || num[0] == '+') {//开头是数字
        const max = Math.pow(2, 31) - 1
        return result > max ? max : result
    }
    else {
        return 0;
    }
};
```

