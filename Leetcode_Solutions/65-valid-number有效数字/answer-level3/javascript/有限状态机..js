```
/**
 * @param {string} s
 * @return {boolean}
 * 
 * 说明:
 * 1.  .1是合法的
 * 2.  数字中间不能有空格，但首位可以有空格
 * 3.  e的指数可以是正负数，但不能是指数
 * 4.  小数也可以接指数
 * 总结:合法十进制数:
 * 1. 正负号
 * 2. 小数或整数
 * 3. 指数 加 数字或正负号数字
 *   开头的正负号可直接接点
 *  * 定义字符类型:
 * 0 数字
 * 1 指数
 * 2 正负号
 * 3 小数点
 * 4 空格
 * -1 其它字符
 */
const states =[]
states[0] = [1, -1,  2,  3,  0]
states[1] = [1,  4, -1,  7,  8]
states[2] = [1, -1, -1,  3, -1]
states[3] = [7, -1, -1, -1, -1]
states[4] = [5, -1,  6, -1, -1]
states[5] = [5, -1, -1, -1,  8]
states[6] = [5, -1, -1, -1,  8]
states[7] = [7,  4, -1, -1,  8]
states[8] = [-1,-1, -1, -1, 8]

var isNumber = function(s) {
    let state = 0
    for(let x of s) {
        const type = cType(x)
        if(type === -1) return false
        state = states[state][type]
        if(state === -1) return false
    }
    if([1, 5, 7, 8].indexOf(state) > -1) return true
    return false
};

function cType(c) {
    if(c == ' ') return 4
    if(!isNaN(c)) return 0
    if(c === 'e') return 1
    if(['+', '-'].indexOf(c) > -1) return 2
    if(c === '.') return 3
    return -1
}
```
