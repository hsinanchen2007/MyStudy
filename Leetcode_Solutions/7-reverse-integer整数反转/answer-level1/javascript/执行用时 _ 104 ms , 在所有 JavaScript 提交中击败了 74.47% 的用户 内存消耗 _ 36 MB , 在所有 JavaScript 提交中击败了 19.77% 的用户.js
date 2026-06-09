```javascript []
var reverse = function (x) {
    let min = Math.pow(-2, 31)
    let max = Math.pow(2, 31) - 1
    let newArgum = ''
    let y = x * -1
    if (x < 0) {
        newArgum = '-'
        y = x
    }
    function resver(x) {
        let strArr = x.toString().split('')
        for (let i = 0; i <= strArr.length - 1; i++) {
            if (i >= Math.floor(strArr.length / 2)) return strArr
            let last = strArr[strArr.length - 1 - i]
            let first = strArr[i]
            strArr[i] = last
            strArr[strArr.length - 1 - i] = first
        }
    }
    let result = newArgum + resver(y * -1).join('')

    if (result > max || result < min) {
        return 0
    }
    return result

};

console.log(reverse(1320))

/**
 * 解题思路：
 * 
 *  1. 只是一个简单的反转数字的题目，题中要求遇到负号负号位子不变，并且规定了取值范围，超出范围返回0即可
 *  2. 首先我们先将负号做一下兼容，让他不影响我们的直接反转数字
 *  3. 反转就是简单的反转，使用reverse也可以，最后将负号加上即可，得出结果返回
 *  4. 判断最大值和最小值超出返回0即可
 */
```
