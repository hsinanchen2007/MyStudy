```
var longestPalindrome = function(s) {
    if (s === '')
        return s
    let maxStr = s[0]
    let len = s.length
    for (let i = 0; i < len - 1; i++) {
        let tempX = s[i]
        let k = 1
        let cutBol = true
        for (let j = i + 1; j < len; j++) {
            if (s[i] === s[j] && cutBol) {
                tempX += s[j]
                continue
            }
            if (i - k < 0) {
                break;
            }
            if (s[j] === s[i - k]) {
                cutBol = false
                tempX = s[i - k] + tempX + s[j]
                k++
            } else {
                break;
            }
        }
        maxStr = tempX.length > maxStr.length ? tempX : maxStr
    }
    return maxStr
};
```
