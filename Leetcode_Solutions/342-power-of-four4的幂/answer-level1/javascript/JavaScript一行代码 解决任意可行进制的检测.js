转换为4进制字符串 若是4的幂次，则字符串以1个1开头，剩余皆为0或无；即用正则匹配即可
```
var isPowerOfFour = function(num) {
    return /^[1]{1}[0]*$/.test(num.toString(4));
};
```
