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
    if(!str1.length || !str2.length) return "";
    const gcd = (a, b)=>{ //辗转相除法：计算两个正整数的最大公约数
        if (a % b == 0) return b;
        return gcd(b, a%b);
    }
    let g = gcd(str1.length, str2.length);
    if(str1 + str2 == str2 + str1){
        return str1.substring(0, g);
    }
    return "";
};
```