### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var validPalindrome = function(s) {

    var isPalindrome = function(str, l, r) {
        let i = l - 1, j = r + 1
        while (++i < --j)
            if (str[i] != str[j]) return 0

        return 1
    };

    let i = 0, j = s.length - 1
    while (i < j) {
        if (s[i] != s[j]) {
            return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1)
        }
        i++, j--
    }

    return 1  
};
```