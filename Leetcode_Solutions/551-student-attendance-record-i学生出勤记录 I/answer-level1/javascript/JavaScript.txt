### 解题思路
好像没什么好解析的。。。

### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var checkRecord = function(s) {
    let a = 0
    let pre = s[0]
    if(pre == 'A') a++
    for (let i = 1; i < s.length; i++) {
        let cur = s[i]
        if(a > 1) return false
        if(cur == 'L' && pre == 'L' && s[i + 1] == 'L') return false
        if(cur == 'A') a++
        pre = cur
    }
    if(a > 1) return false
    return true
};
```