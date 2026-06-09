### 思路

本题在思路上其实并不复杂，最为麻烦的是我们要考虑到各种特殊情况，除了题目中举出的例子之外，还有以下两种情况需要考虑:
```
// e之后首位+/-号
'005047e+6' => true
'005047e-6' => true
// . 号前后缺位
'.3' => true
'3.' => true
```

接着我们可以根据题目中列举的情况作出条件的总结:

* 字符串前后可有空字符，如 `' 23 '`
* 允许小数及科学计数法，即 `1.0`和`1e2`。
* 小数点`.`仅可出现在`e`之前，即`1.0e1`有效，`1e1.0`无效。
* 数字起始允许有`+/-`正负号。
* 'e'之后首位允许有`+/-`正负号。
* 小数点可以省略前面或者后面的数字，如`1.`和`.1`有效，`.`无效。

### 完整题解
    执行用时 :96 ms, 在所有 javascript 提交中击败了90.63%的用户
    内存消耗 :37.2 MB, 在所有 javascript 提交中击败了30.56%的用户
```JavaScript []
var isNumber = function (s) {
    const checkNumber = (str) => {
        const numReg = new RegExp(/[0-9]/);
        // 标记是否出现过数字，防止 '.' ' +' 或者 ' ' 的情况
        let decimal = false,
            // 判断点号是否无效, true 为无效，防止 '1.1.1' 和 '1e2.5' 的情况
            point = false,
            // 判断'e'号是否无效, true 为无效，防止'1e1e'的情况
            exponent = false,
            // 记录'e'出现的位置，判断'e'后接正负号的情况, 如 '1e-10'
            exponentPlace = -1;
        for (let i = 0; i < str.length; i++) {
            if (str[i] === '+' || str[i] === '-') {
                // 若出现'+/-'，而且不在字符的首位或'e'之后的首位，返回错误。
                if (i !== 0 && i !== exponentPlace + 1) {
                    return false;
                }
            } else if (str[i] === '.') {
                // 判断点号是否有效，若有效则设 point 为true，不可再次出现点号。
                if (point) {
                    return false;
                } else {
                    point = true;
                }
            } else if (str[i] === 'e') {
                // 若已出现'e'或者在遇到'e'之前没有出现过数字，即'e1'的情况，返回无效。
                if (exponent || !decimal) {
                    return false;
                } else {
                    // 设 exponent 为 true，避免再次出现'e'的情况
                    exponent = true;
                    // 'e'之后不可出现点号
                    point = true;
                    // 'e'之后必须有数字
                    decimal = false;
                    // 记录 'e' 的位置，用于判断 '1e+10' 以及 '1e1-10' 的状况
                    exponentPlace = i;
                }
            } else if (numReg.test(str[i])) {
                decimal = true;
            } else {
                // 如果不为 [0-9e.\-+\s] 中的字符，返回 false
                return false;
            }
        }
        return decimal;
    }
    return checkNumber(s.trim());
};
```