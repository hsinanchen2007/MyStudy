1、数字转字符串 遍历查找
```js
var isPalindrome = function(x) {
    let sx = String(x)
    let i = 0; j = sx.length - 1
    while (i < j) {
        if (sx[i] !== sx[j]) {
            return false
        }
        else {
            i++
            j--
        }

    }
    return true
};
```

2、数字转字符串转数组倒叙判断是否一致
```js
var isPalindrome = function(x) {
    let sx = String(x)
    let retx = sx.split("").reverse().join("")
    return sx === retx
};
```