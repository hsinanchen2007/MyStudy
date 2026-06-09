### 解题思路
1. 将整数取绝对值，转换为字符串，使用String.split('')分割成单个字符；
2. 使用Array.reverse()反转顺序，再使用String.join('')拼接成字符串；
3. 如果输入值小于0，则乘以-1转换成数字，否则乘以1转换成数字；
4. 判断得到的数字是否处于允许的范围内，如果合法则返回数字，否则返回0。

### 代码

```javascript
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    const xArr = (Math.abs(x) + '').split('');
    const xStr = (xArr.reverse()).join('');
    let xNum;
    if (x < 0) {
        xNum = xStr * -1;
    } else {
        xNum = xStr * 1;
    }
    if (xNum <= Math.pow(2, 31) - 1 && xNum >= -Math.pow(2, 31)) {
        return xNum;
    }
    return 0;
};
```