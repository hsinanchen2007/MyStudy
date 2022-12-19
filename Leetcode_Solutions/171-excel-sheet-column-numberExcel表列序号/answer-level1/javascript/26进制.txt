### 解题思路
此处撰写解题思路
 * 根据字符的ASCII码，找到表示的数字值
 * 根据表名称字符串的长度
 * 相当于一个26进制的数字
### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var titleToNumber = function(s) {
    let arr = s.split("")
    let first = arr[0].charCodeAt()-64
    let len = arr.length
    let result=0
    for(let i=0;i<len;i++){
        result+=(arr[i].charCodeAt()-64)*Math.pow(26,len-i-1)
    }
    return result
};
```