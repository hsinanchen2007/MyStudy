```javascript []
var removeOuterParentheses = function (S) {
    let num = 1;
    let float = 0
    let ret = '';
    for(let i = 0; i <= S.length - 1; i++) {
        if(S[i] === '(') {
            num++ 
        } else {
            num--
        }
        if (num === 1) {
            ret += S.slice(float + 1, i)
            float = i + 1
        }
        
    }
    return ret
};
```

/**
 * 解题思路：
 * 
 *  1. 遍历该字符串，判断如果遍历出来的每一项等于“（” 则让num + 1 否则 - 1
 *  2. 如果num 为 1 则说明匹配到了一套完整的括号
 *  3. 使用字符串截取 【截取位置 （ 第一次初始化float + 1， 匹配到完整的括号的下标 ）】，并且记录float的位置也就是上一次匹配到完整的括号的下标
 */

