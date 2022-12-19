### 代码

```javascript
var backspaceCompare = function(S, T) {
    if (S === T) {
        return true
    }
    const res1 = helper(S)
    const res2 = helper(T)
    if (res1 === res2) {
        return true
    } else {
        return false
    }
};
const helper = s => {
    const arr = s.split('')
    const res = []
    for (let i = 0; i < s.length; i++) {
        if (s[i] === '#') {
            res.pop()
        } else {
            res.push(s[i])
        }
    }
    return res.join('')
}
```
时间复杂度：O(2n)
空间复杂度：O(2n)