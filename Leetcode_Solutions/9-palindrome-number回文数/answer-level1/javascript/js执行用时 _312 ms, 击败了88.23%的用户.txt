```
var isPalindrome = function(x) {
    let xs = Math.abs(x) //先转化为绝度值
    xs = xs + '' // 转为字符串，经过试验，这种转化比toString()快很多
    let iso, length
    let ise = false //判断是否为负数 负数直接给false
    if (x < 0) {
        ise = true
    }
    ((x + '').length) % 2 == 0 ? iso = true : iso = false //判断奇偶数
    if (iso) { //偶数的循环长度不减1
        length = Math.floor((xs.length) / 2)
        for (let i = 0; i <= length; i++) {
            if (xs[i] != xs[(x + '').length - 1 - i] || ise) {
            return false
            }
        }
    } else { //奇数的循环长度减1 你们懂得
        length = Math.floor(xs.length / 2) - 1
        for (let i = 0; i <= length; i++) {
            if (xs[i] != xs[(x + '').length - 1 - i] || ise) {
                return false
            }
        }
    }
    return true //如果没有问题，最后返回true
}
```

