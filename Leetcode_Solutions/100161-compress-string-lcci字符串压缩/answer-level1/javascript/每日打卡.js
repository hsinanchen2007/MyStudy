### 解题思路
双指针遍历就完事了

### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var compressString = function(S) {
    if (S.length < 2) {
        return S
    }
    let res = ''
    let i = 0
    while (i < S.length) {
        let j = i + 1
        let num = 1
        while (j < S.length) {
            if (S[i] === S[j]) {
                j++
                num++
            } else {
                break
            }
        }
        res += `${S[i]}${num}`
        i += j - i
    }
    return S.length > res.length ? res : S
};
```