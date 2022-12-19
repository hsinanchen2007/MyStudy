### 解题思路
借鉴了以为老兄的思路。
但是时间复杂度有点高，空间还可以80%多。

### 代码

```javascript
/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
    let ret = [1];
    const len = digits.length;
    console.log(len);
    for (let i = len - 1; i >= 0; i--) {
        digits[i] += 1;
        digits[i] %= 10;
        if (digits[i] == 0) {
            continue;
        } else {
            break;
        }
    }
    if (digits[0] == 0) {
        ret = ret.concat(digits);
        return ret;
    } else {
        return digits;
    }
};
```