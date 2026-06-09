```
/**
 * @param {string} s
 * @return {boolean}
 * 先用正则去除干扰字符
 * 双指针
 */
var isPalindrome = function(s) {
    s = s.replace(/([^a-zA-Z0-9])/g, '');
    for (let i = 0, j = s.length - 1; i < j; i++,j--) {
        if (s[i].toLocaleLowerCase() !== s[j].toLocaleLowerCase()) {
            return false;
        }
    }
    return true;
};
```