### 解题思路
中心位分为单个字符、两个相等字符 两种情况分别计算最大回文串
### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    let max_Sub = s.length>0?s[0]:s
    // 以单个字符为中心位
    let i = 0
    for (; i < s.length-1; i++) {
        let l = 1
        let r = 1
        while(i>=l && i+r<s.length) {
            if (s[i-l]==s[i+r]) { // i位置为对称轴，向两边扩散
                max_Sub = (l+r+1)>max_Sub.length?s.slice(i-l, i+r+1):max_Sub;
                l++
                r++
            }
            else {
                break
            }
        }
    }
    // 以两个字符为中心位
    i = 0
    for (; i < s.length-1; i++) {
        if (s[i]==s[i+1]) {
            max_Sub = max_Sub.length>2?max_Sub:(s[i]+''+s[i+1])
            let l = 1
            let r = 2
            while(i>=l && i+r<s.length) {
                if (s[i-l]==s[i+r]) { // i、i+1两个位置为对称轴，向两边扩散
                    max_Sub = (l+r+1)>max_Sub.length?s.slice(i-l, i+r+1):max_Sub;
                    l++
                    r++
                }
                else {
                    break
                }
            }
        }
    }
    return max_Sub
};
```