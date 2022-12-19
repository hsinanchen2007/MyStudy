### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var compressString = function(S) {

    let ans = "", i = j = 0 // 精妙...
    while (j < S.length - 1) {
        if (S[j] !== S[j + 1]) {
            ans += S[i] + (j - i + 1)
            i = j + 1
        }
        j++
    }

    ans += S[i] + (j - i + 1)
    return ans.length < S.length ? ans : S
};
```