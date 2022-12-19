### 解题思路
1. 从末尾开始取得每一个字符对应的数cur = c.charCodeAt() - 64
2. 数字总和sum += 当前数 * 进制位数
3. 进制位数 *= 26，初始化进制位数carry = 1

### 代码

```javascript
var titleToNumber = function(s) {
    let sum = 0, i = s.length - 1, carry = 1;

    while (i >= 0) {
        let cur = s[i].charCodeAt() - 64;

        sum += cur * carry;
        carry *= 26;
        i--;
    }

    return sum;
};
```