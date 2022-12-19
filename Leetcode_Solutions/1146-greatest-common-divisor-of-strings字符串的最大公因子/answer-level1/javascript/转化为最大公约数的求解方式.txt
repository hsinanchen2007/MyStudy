```javascript
/**
 * @param {string} str1
 * @param {string} str2
 * @return {string}
 */
var gcdOfStrings = function(str1, str2) {
    if(str1+str2 !== str2+str1) {
        return ""
    }
    let gcd = (num1,num2)=> num2 === 0?num1:gcp(num2,num1%num2);
    return str1.slice(0,gcd(str1.length,str2.length))
};
```

