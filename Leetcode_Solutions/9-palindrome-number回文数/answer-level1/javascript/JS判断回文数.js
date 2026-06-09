### 解题思路
1、0-9均为回文数
2、负数判断为false
3、大于等于10并且个位数字为0的判断为false
4、循环x，反转数字的后半部分
5.判断x===num，x为前一半的值，num为后一半的值的反转

### 代码

```javascript
/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    if (x >= 0 && x < 10) return true
    else if (x < 0 || x % 10 === 0) return false
    let num = 0
    while (x > num) {
        num = num * 10 + x % 10
        x = x > num ? Math.floor(x / 10) : x
    }
    return x === num
};
```