1. countAndSay 函数
    判断特殊情况入参`n`为`1`时 直接返回 `'1'`
    遍历`n`，利用`say`函数重置`str`，共计重置`n-1`次
    遍历完成返回 `str`


2. 函数say 中传入上一个str的值
    声明 `result`保存下一个将要生成的`str`
    声明 `j` 保存相连续相同值得个数 并遍历`str`
    判断当前的`str[i]`与`str[i]`是否相同
    相同的值 `j++`
    不相同 `result += j + str[i]` 并初始化`j`为`1`
    最终返回 `result`
3. 不多说 直接撸代码   
```
/**
 * @param {number} n
 * @return {string}
 */
var countAndSay = function (n) {
    let str = '1'
    if (n === 1) return str
    for (let i = 0; i < n-1; i++) {
        str = say(str)
    }
    return str
};

var say = function (str) {
    let result = ''
    let j = 1
    for (let i = 0; i < str.length; i++) {
        if (str[i] === str[i + 1]) {
            j++
            continue
        } else {
            result += j + str[i]
            j = 1
        }
    }
    return result
}

```


