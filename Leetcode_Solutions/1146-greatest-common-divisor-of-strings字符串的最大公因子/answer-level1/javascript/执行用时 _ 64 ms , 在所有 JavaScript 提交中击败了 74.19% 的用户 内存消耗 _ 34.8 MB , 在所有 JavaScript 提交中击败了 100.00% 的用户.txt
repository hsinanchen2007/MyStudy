### 解题思路
 1. 如果能除尽就说明用正则全局替换完之后剩余一个空字符串
 2. 如果能除尽，那么他们公共字符串的长度肯定是两个字符串的公约数

### 代码

```javascript
/**
 * @param {string} str1
 * @param {string} str2
 * @return {string}
 */
var gcdOfStrings = function(str1, str2) {
    let len1 = str1.length,len2 = str2.length
    for(let len = Math.min(len1, len2),i = len; i>0; i--) {
      if(len1%i ===0 && len2 %i ===0) {
        let str = str1.slice(0, i)
        // 如果str2不是以str打头，那么str肯定不是公约数
        if(!str2.startsWith(str)) return ''
        if(str1.replace(new RegExp(str,'g'),'') === '' && str2.replace(new RegExp(str,'g'),'') === '') {
          return str
        }
      }
    }
    return ''
};
```