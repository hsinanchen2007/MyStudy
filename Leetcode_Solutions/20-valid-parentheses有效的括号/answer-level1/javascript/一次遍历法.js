```
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    const leftArr = []
    const listMap = {
        '(': ')',
        '[': ']',
        '{': '}'
    }
    for(item of s) {
        if (item in listMap) leftArr.push(item)
        else if (listMap[leftArr[leftArr.length-1]] === item) leftArr.pop()
        else return false
    }
    return !leftArr.length
};
```
左半边括号存入数组，第一个出现的右半边括号必须匹配存入数组的最后一项