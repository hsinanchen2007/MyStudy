### 解题思路

 * 遍历一遍s，使用set保存字母e，
 * 有重复的，长度+2，并去除
 * 不存在，则添加
 * 最后，看set，非空则长度+1

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function(s) {
    let len = 0;
    let chars = new Set();
    for(let e of s) {
        if(chars.has(e)) {
            len += 2;
            chars.delete(e);
        } else {
            chars.add(e);
        }
    }

    if(chars.size !== 0) {
        len += 1;
    }

    return len;
};
```