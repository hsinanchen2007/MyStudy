### 解题思路

先用split将字符串拆分，然后利用filter筛选数组，用indexOf和lastIndexOf找出只出现一次的字符。
如果没有返回空格" "，否则返回筛选完成后的数组下标为0的字符。

### 代码

```javascript
/**
 * @param {string} s
 * @return {character}
 */
var firstUniqChar = function(s) {
    if(!s) return " "

    const result = s.split("").filter(item => {
        return s.indexOf(item) === s.lastIndexOf(item) 
    })

    if(result.length === 0) {
        return " "
    } else {
        return result[0]
    }
};
```