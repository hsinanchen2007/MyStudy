### 解题思路

![image.png](https://pic.leetcode-cn.com/e276a821e0c5da1c751f46749fe2023b10bcd3542cef730d3feb59a9b2cc1f2d-image.png)

### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var compressString = function(S) {
    if (S.length < 3) return S;
    let length = 1, res = '', count = 1;
    while (length <= S.length) {
        if (S[length] === S[length-1]) {
            count++
        } else {
            res += S[length - 1] + count;
            count = 1;
        }
        length++;
    }
    return res.length < S.length ? res : S;
};
```