关键在于两个字符串都  **除尽**
其实根本就是求最大公约数
因为如果存在这个公约字符串 那么这两个字符串都是这个字符串的重复

解法1
```
var gcdOfStrings = function (str1, str2) {
    if(str1 + str2 !== str2 + str1) return ''
    let X = 0
    let n1 = str1.length
    let n2 = str2.length
    for(let i = Math.min(n1,n2); i>0 ; i--){
        if(n1%i===0 && n2%i===0){
            X = i;
            break
        }
    }
    return str1.substr(0,X)
};
```

解法2
```
var gcdOfStrings = function (str1, str2) {
    if(str1 + str2 !== str2 + str1) return ''
    let n1 = str1.length
    let n2 = str2.length
    let gcd = (a,b)=>(b===0?a:gcd(b,a%b))
    return str1.substr(0,gcd(n1,n2))
};

```

