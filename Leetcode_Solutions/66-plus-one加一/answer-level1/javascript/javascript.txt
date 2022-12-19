### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
    const result = [];
    digits = digits.reverse();
    let sum = digits[0] + 1;
    let flag = Math.floor(sum / 10);
    let ret = sum % 10;
    if(digits.length === 1) {
        result.push(sum);
        return result.join('').split('');
    }
    result.push(ret);

    for(let i = 1;i < digits.length;i ++) {
        if(i === digits.length - 1) {
            sum = digits[i] + flag;
            result.push(`${sum}`.split('').reverse().join(''));
        } else {
            sum = digits[i] + flag;
            flag = Math.floor(sum / 10);
            ret = sum % 10;
            result.push(ret);
        }
    }
    return result.join('').split('').reverse();
};
```