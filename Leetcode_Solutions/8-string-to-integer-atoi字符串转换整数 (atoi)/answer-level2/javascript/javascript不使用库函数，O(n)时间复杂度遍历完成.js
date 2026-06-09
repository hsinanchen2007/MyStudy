```
/**
 * 丢弃前面的空格字符
 * 第一个非空字符可以是正负号或数值，不能是其它字符
 * @param {string} str
 * @return {number}
 */
var myAtoi = function(str) {
    // 是否是负数
    let isNagetive = false
    // 起始位
    let start = 0

    // 遍历到第一个非空字符
    while(start < str.length) {
        if (str[start] !== ' ') {
            break
        }
        start++
    }

    if (str[start] === '-') {
        isNagetive = true
        // 往后移动一位
        start++
    } else if (str[start] === '+') {
        isNagetive = false
        // 往后移动一位
        start++
    } else {
        if (!isVaildNumChar(str, start)) {
            // 第一位非空字符不是正负号或者0~9范围的数字
            return 0
        }
    }

    let end = start
    // 遍历直到遇到无效字符，或者结尾
    while(end < str.length) {
        if (!isVaildNumChar(str[end])) {
            break
        }
        end++
    }
    let multiple = 1
    let result = 0
    let count = 0

    // 这里先统一为正
    const maxNumber = isNagetive ? 2147483648 : 2147483647

    // 从尾部遍历
    for(let i = end - 1; i >= start; i--) {
        // 第10位开始得检查下，可能要溢出了
        if (++count >= 10) {
            if (maxNumber - result < (str.charCodeAt(i) - 48) * multiple) {
                result = maxNumber
                break
            }
        }
        result += (str.charCodeAt(i) - 48) * multiple
        multiple *= 10
    }
    return isNagetive ? -result : result
};

/**
 * 是否是0~9范围
 */
var isVaildNumChar = function(str, index) {
    const charCode = str.charCodeAt(index)
    return charCode >= 48 && charCode <= 57
}
```
