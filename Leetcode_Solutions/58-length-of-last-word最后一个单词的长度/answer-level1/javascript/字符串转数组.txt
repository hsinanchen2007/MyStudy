### 解题思路
对非空字符串，去掉首位空格；将字符串中所有空格替换成特殊符号；将字符串按特殊字符切割成数组；获取最后一个元素的长度。

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    if (!s) {
        return 0
    }

    let str = s.trim().replace(/\s/g, ',')
    let arr = str.split(',')
    return arr.pop().length
};
```