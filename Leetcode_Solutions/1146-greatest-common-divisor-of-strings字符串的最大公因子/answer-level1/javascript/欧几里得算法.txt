### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} str1
 * @param {string} str2
 * @return {string}
 */
var gcdOfStrings = function(str1, str2) {
    //如果两个字符串用不同的顺序拼接之后不相等，则一定没有最大公因子
    if((str1 + str2) != (str2 + str1)){
        return ''
    }
    if (str2.length == 0) return str1;
    return str1.substring(0,gcd(str1.length,str2.length))
};

//欧几里得算法

function gcd(a, b) {
        if (a % b == 0) return b;
        return gcd(b, a % b);
    }
```