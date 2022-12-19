### 解题思路
执行用时: 92 ms, 在所有 JavaScript 提交中击败了91.01%的用户  
内存消耗: 42.9 MB, 在所有 JavaScript 提交中击败了32.61%的用户
首先判断输入的字符串是否是回文字符串：使用两个指针，一个从左至右遍历，一个从右至左遍历，这两个指针每同时移动一个位置，判断当前字母是否相同。如果遍历结束后都相同，则这个字符串是回文字符串。当存在不同时，可以使左边的指针向右移动一个位置，或使右边的指针向左移动一个位置跳过当前字母，并判断两个指针中间剩余的字符串是否为回文字符串，相当于删除了当前字母。如果剩余字符串是回文字符串，则原字符串可删除一个字母成为回文字符串；如果剩余字符串还不是回文字符串，则说明原字符串即便删除一个字母后，仍然不是回文字符串。

### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var validPalindrome = s => {

    let isPalindrome = (s, lo = 0, hi = s.length - 1) => {
        for (; lo < hi; lo++, hi--) {
            if (s[lo] != s[hi]) {
                let bool = false
                return {lo: lo, hi: hi, bool: bool}
            }
        }
        let bool = true
        return {lo: lo, hi: hi, bool: bool}
    }
    
    if (isPalindrome(s).bool) {
        return true
    } else {
        let [lo, hi] = [isPalindrome(s).lo, isPalindrome(s).hi]
        return isPalindrome(s, lo + 1, hi).bool || isPalindrome(s, lo, hi - 1).bool
    }

}
```