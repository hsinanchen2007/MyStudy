### 解题思路
如果两个字符串有公因子，那么两个字符串不同的部分必然也包括了公因子，相当于str3。
接着再用str3与较短的字符串对比，不同的部分继续与较短的对比。
直到不同的部分和较短的字符串相同，它就是最大公因子


### 代码

```javascript
/**
 * @param {string} str1
 * @param {string} str2
 * @return {string}
 */
var gcdOfStrings = function(str1, str2) {
    if(str1 === str2){ return str1;}
    let [s1,s2] = str1.length > str2.length ? [str1,str2] : [str2,str1];
    if(!new RegExp(`^[${s2}]+$`).test(s1)){return ''};
    return gcdOfStrings(s2,s1.replace(s2,''))
};
```