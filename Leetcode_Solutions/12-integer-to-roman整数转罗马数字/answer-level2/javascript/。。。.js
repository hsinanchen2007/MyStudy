```
/**
 * @param {number} num
 * @return {string}
 */
var intToRoman = function (num) {
    let tag = {
        '1': 'I',
        '4': 'IV',
        '5': 'V',
        '9': 'IX',
        '10': 'X',
        '40': 'XL',
        '50': 'L',
        '90': 'XC',
        '100': 'C',
        '400': 'CD',
        '500': 'D',
        '900': 'CM',
        '1000': 'M',
    }
    let s = ''
    let i = 1
    while (num > 0) {
        let m = num % 10 + '' // 各位对应的数字
        let n = num % 10 * i + ''// 各位对应的数值
        s = (tag[n] ? tag[n] : m < 4 ? tag[i + ''].repeat(m) : tag[5 * i + ''] + tag[i + ''].repeat(m - 5)) + s
        i = i * 10
        num = parseInt(num / 10)
    }
    return s
};
```

* tag[n] ? tag[n] : m < 4 ? tag[i + ''].repeat(m) : (tag[5 * i + ''] + tag[i + ''].repeat(m - 5)) 获取当前位置罗马数字表达式
* tag[i + ''].repeat(m) 位上数字小于4，直接重复
* tag[5 * i + ''] + tag[i + ''].repeat(m - 5) 排除前置情况，其实就是位上数字位于6-8，先获取V/L/D,然后加上重复
