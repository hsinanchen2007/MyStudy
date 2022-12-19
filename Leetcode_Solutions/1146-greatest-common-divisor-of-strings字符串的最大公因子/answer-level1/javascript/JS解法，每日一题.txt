### 解题思路
（该题借鉴思路）
这道题需要阅读出隐藏条件：如果有解的话应该满足str1+str2===str2+str1；
求公约数需要用到**辗转相除法（欧几里得算法）**，可以求得最大公约字符串的位数，直接截取即可。

辗转相除法（欧几里得算法）：gcd=(a,b)=>(b===0?a:gcd(b,a%b))。

### 代码

```javascript
/**
 * @param {string} str1
 * @param {string} str2
 * @return {string}
 */
var gcdOfStrings = function(str1, str2) {
    if(str1+str2!==str2+str1) return"";
    const gcd=(a,b)=>(b===0?a:gcd(b,a%b))
    return str1.slice(0,gcd(str1.length,str2.length))
};
```