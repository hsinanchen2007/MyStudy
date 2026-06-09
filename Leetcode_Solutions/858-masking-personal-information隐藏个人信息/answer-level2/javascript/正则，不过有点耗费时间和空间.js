### 解题思路
首先删掉数据中所有的`-`、`(`、`)`、`+`
包含`@`的，肯定是邮箱，直接替换处理
剩下的电话号码，长度大于10的是国际号，否则是本地号

### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var maskPII = function(S) {
    S = S.replace(/[\+\-\(\)\s]/g,'')
    if(S.includes('@')) return S.toLowerCase().replace(/^(\w)[\w]*(\w)(@.*)$/,'$1*****$2$3')
    else if(S.length > 10)  return S.replace(/.*([\d]{4})$/,`+${'*'.repeat(S.length - 10)}-***-***-$1`)
    else return S.replace(/.*([\d]{4})$/,'***-***-$1')
};
```