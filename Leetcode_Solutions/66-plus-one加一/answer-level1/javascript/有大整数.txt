### 解题思路
![image.png](https://pic.leetcode-cn.com/5e769e01d55500ea2852414a72139081f5c42e555e1856312da2dd9ec9f61c7f-image.png)

一开始用join, parseInt，toString, split大法，结果有超出int范围的大数，只能老老实实写数组。
### 代码

```javascript
/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
    if (digits[0] === 0) return [1];
    let i = digits.length - 1;
    digits[i] += 1;
    if (digits[i] != 10) return digits;

    digits[i] = 0;
    i--;
    while (i >= 0) {
        if (digits[i] < 9) {
            digits[i]++;
            return digits;
        } else {
            digits[i] = 0;
            i--;
        }
    }
    digits.unshift(1);
    return digits;
};
```