### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var removeOuterParentheses = function (S) {
    let target = '';
    let str = '';
    let count = 0;
    let ans = ''
    for (let i = 0; i < S.length; i++) {
        if (!target) target = S[i];
        if (target === S[i]) {
            count++;
        } else {
            count--;
        }
        str += S[i];
        if (count === 0) {
            target = '';
            ans += str.substring(1, str.length - 1);
            str = '';
        }
    }
    return ans;
};
```