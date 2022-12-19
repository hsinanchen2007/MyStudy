### 解题思路
清晰

### 代码

```javascript
/**
 * @param {string} s
 * @param {number} n
 * @return {string}
 */
var reverseLeftWords = function(s, n) {
    //转换数组
    const strArr  = s.split("");
    //截取n之后的字符串
    const subStrArr = strArr.slice(n);
    //合并字符串
    const newStrArr = subStrArr.concat(strArr.slice(0,n));
    //数组转字符串
    return newStrArr.join("")
};
```