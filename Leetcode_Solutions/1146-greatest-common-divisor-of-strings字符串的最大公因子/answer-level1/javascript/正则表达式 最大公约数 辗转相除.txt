### 解题思路

辅助方法，判断x是否为str的公因子，可以使用正则表达式match

最大公约数 辗转相除法

看了题解改成了，最大公约数的方法，跟暴力法相比效率成倍提升

### 代码

```javascript

/**
 * 辅助方法，判断x是否为str的公因子，可以使用正则表达式match
 * 
 * 判断最大公约数
 * @param {string} str1
 * @param {string} str2
 * @return {string}
 *  
 */
var gcdOfStrings = function (str1, str2) {
    let len1 = str1.length;
    let len2 = str2.length;
    if(len1 === 0 || len2 === 0) return '';

    let gcdNum = 1;
    if(len1 > len2) {
        gcdNum = gcd(len1, len2);
    } else {
        gcdNum = gcd(len2, len1);
    }

    let str = str1.substr(0, gcdNum);
    if(isGcd(str, str1) && isGcd(str, str2)) {
        return str1.substr(0, gcdNum);
    } else {
        return '';
    }
}

//公因子
function isGcd(x, str) {
    let reg = new RegExp(`^(${x})+$`, 'i');
    return reg.test(str);
}

//最大公约数
//num1 > num2
function gcd(num1, num2) {
    let tmp = num1 % num2;
    if(tmp === 0) {
        return num2;
    } else {
        return gcd(num2, tmp)
    }
}

```