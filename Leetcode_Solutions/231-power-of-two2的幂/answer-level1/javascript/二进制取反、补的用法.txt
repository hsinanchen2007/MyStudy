### 1. 利用2的余数与除数
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfTwo = function(n) {
    if(n == 0) {
        return false;
    }
    while(n%2 == 0) {
        n = n / 2;
    }
    // 2的所有幂最后都归为1
    if(n == 1) {
        return true;
    } else {
        return false;
    }
        
};
```
### 2. 利用 （2的幂次方 － 1）&  （2的幂次方）＝＝ 0
二的幂次数在计算机中存储的一定是2^n = 1000000
2^n -1 = 01111111
所以两个与一定为0
```
var isPowerOfTwo = function(n) {
    if(n == 0) 
        return false;
    var p = n & (n - 1);

    return (p == 0);   
};
```
但是执行完之后报错，在输入为负数的情况下错误，因此要考虑为负数的情况，修改为
```
return (n > 0) && (p == 0);
```
### 3.官方发布的获取2次幂 二进制最右边的1
在js中，负数也存储为二进制代码，不过采用的形式是二进制补码。
注意：在处理有符号整数时，开发者不能访问 31 位。
要注意js中由于对负数的表示不同，是与c不一样的，具体看https://www.w3school.com.cn/js/pro_js_operators_bitwise.asp

https://leetcode-cn.com/problems/power-of-two/solution/2de-mi-by-leetcode/