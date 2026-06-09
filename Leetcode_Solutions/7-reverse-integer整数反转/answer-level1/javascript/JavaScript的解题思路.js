### 解题思路
1. Math.abs(x)取x的绝对值；
2. 判断x是否为负数，是则提取x的符号；
3. 得到反转后的数组：对【1】所得数字split成数组，再reverse反转；
4. 用join处理【3】所得数组；
5. 得到结果：【2】与【4】转为数字；
6. 判断数字是否符合题干32位说法，是则返回【5】，否则返回 0；

### 代码

```javascript
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    var prefix = '';
    // 1、Math.abs(x)取x的绝对值；
    var absX = Math.abs(x);
    // 2、判断x是否为负数，是则提取x的符号；
    if (x < 0) {
        prefix = '-';
    }
    // 3、得到反转后的数组：对【1】所得数字split成数组，再reverse反转；
    var arr = String(absX).split('');
    var reverseArr = arr.reverse();
    // 4、用join处理【3】所得数组；
    var reverseStr = reverseArr.join('');
    // 5、得到结果：【2】与【4】转为数字；
    const result =  Number(prefix + reverseStr);
    // 6、判断数字是否符合题干32位说法，是则返回【5】，否则返回 0；
    if (result < Math.pow(-2, 31) || result > (Math.pow(2, 31) - 1)) {
        return 0;
    } else {
        return result;
    }
};
```