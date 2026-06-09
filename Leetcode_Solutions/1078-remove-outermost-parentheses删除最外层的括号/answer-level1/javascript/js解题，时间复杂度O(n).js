变量stack记录当前字符的状态，当字符为(则+1，)则减1『由于只有小括号故直接用数字来计算而不用数组』
可知在对stack计算前最外层的(时stack必为0
在对stack计算后最外层的)也必为0

当stack不为0时将字符加入字符串中
该算法的时间复杂度为O(n)

```js
/**
 * @param {string} S
 * @return {string}
 */
var removeOuterParentheses = function(S) {
    let stack = 0;
    let str = '';
    let len = S.length;
    for (let i = 0; i < len; i++) {
        let char = S[i];
        if (char === '(') {
            if (stack !== 0) {
                str = str + char;
            }
            stack+=1;
        } else if (char === ')') {
            stack-=1
            if (stack !== 0) {
                str = str + char
            }
        }
    }
    return str;
};
```
