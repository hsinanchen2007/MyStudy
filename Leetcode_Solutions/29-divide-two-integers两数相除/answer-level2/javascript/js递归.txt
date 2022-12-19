### 解题思路
![image.png](https://pic.leetcode-cn.com/2f4c7f80f7ee5b22ca7e0536a9a41e3ff74df902657cae8d10b0ab9a24c6a119-image.png)


### 代码

```javascript
/**
 * @param {number} dividend
 * @param {number} divisor
 * @return {number}
 */
var divide = function(dividend, divisor) {
    if (!dividend) return 0;
    if (divisor === 1) {
        if (dividend > 0) {
            return dividend > Math.pow(2,31) -1 ? Math.pow(2,31) -1: dividend;
        } else {
            return dividend < -Math.pow(2,31) ? Math.pow(2,31): dividend;
        }
    } else if (divisor === -1) {
        if (-dividend > 0) {
            return -dividend > Math.pow(2,31) -1 ? Math.pow(2,31) -1: -dividend;
        } else {
            return -dividend < -Math.pow(2,31) ? -Math.pow(2,31): -dividend;
        }
    }
    let flag = '+';
    if ((dividend >0 && divisor < 0) || (divisor > 0 && dividend < 0)) {
        flag = '-';
    }
    divisor = Math.abs(divisor);
    dividend = Math.abs(dividend);
    if (divisor > dividend) return 0;
    let res = 0;
    function getRes(left) {
        let ans = 1, cur = divisor;
        while (cur <= left) {
            cur += cur;
            ans += ans;
        }
        ans = ans / 2;
        cur = cur / 2;
        if (left - cur >= divisor) {
            return ans + getRes(left - cur);
        } else {
            return ans;
        }
    }
    res = getRes(dividend);
    if (flag === '+' && res > (Math.pow(2, 31) - 1)) {
        return Math.pow(2, 31) - 1;
    } else if (flag === '-' && res < -Math.pow(2, 31)) {
        return -Math.pow(2, 31);
    }
    return Number(flag + res);
};
```