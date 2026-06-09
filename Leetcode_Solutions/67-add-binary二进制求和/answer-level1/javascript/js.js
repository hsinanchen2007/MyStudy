```
/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 * 1. 直接使用 parseInt toString 在数值过大时容易丢失。
 * 2. 给一个进位标志符 carry 结合 a[i] b[i] 是否相等以及 carry得到新的位数。
 */
var addBinary = function(a, b) {
    let res = '';
    let carry = false;
    for (let i = a.length - 1, j = b.length - 1;;i--,j--) {
        if (!a[i] && !b[j])
            break;
        if (a[i] && b[j]) {
            if (a[i] === b[j]) {
                res += carry ? '1' : '0';
                carry = a[i] === '1';
            } else {
                res += carry ? '0' : '1';
            }
        } else {
            let currentExist = a[i] ? a[i] : b[j];
            res += carry
                ? currentExist === '1'
                    ? '0'
                    : '1'
                : currentExist;
            carry = carry && currentExist === '1' ? true : false
        }
    }
    if (carry) {
        res += '1';
    }
    return res.split('').reverse().join('');
};
```