#### 左右分，主要是判断是否符合数字要求，我用了js中的恶Number再转字符串比较
```javascript
    return str==new Number(str).toString()
```
#### 完整代码如下
```javascript
/**
 * @param {string} S
 * @return {string[]}
 */
var ambiguousCoordinates = function (S) {
    let result = []
    S = S.substring(1, S.length - 1)
    for (let i = 1, len = S.length; i < len; i++) {
        let tarr = [S.slice(0, i), S.slice(i)]
        let leftArr = convert(tarr[0]), rightArr = convert(tarr[1])
        for (let j = 0; j < leftArr.length; j++) {
            for (let k = 0; k < rightArr.length; k++) {
                result.push('(' + leftArr[j] + ', ' + rightArr[k] + ')')
            }
        }
    }
    return result
};

var convert = function (str) {
    if (str.length == 1) {
        return [str]
    }
    let res = []
    for (let i = 1, len = str.length; i < len; i++) {
        let s = insertStr(str, i, '.')
        if (match(s)) {
            res.push(s)
        }
    }
    if (match(str)) {
        res.push(str)
    }
    return res
}


var insertStr = (soure, start, newStr) => {
    return soure.slice(0, start) + newStr + soure.slice(start)
}

var match = function (str) {
    if (isNaN(str)) {
        return false
    }
    if (new Number(str).toString() != str) {
        return false
    }
    return true
}

```