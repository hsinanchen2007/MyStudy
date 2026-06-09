### 解题思路
此处撰写解题思路
- 执行用时 :196 ms, 在所有 JavaScript 提交中击败了96.43%的用户
- 内存消耗 :45.3 MB, 在所有 JavaScript 提交中击败了78.43%的用户
### 代码

```javascript
/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    if (x < 0) return false;
    if (x < 10) return true;
    const s = (x + '').split('');
    let flag  = true;
    for (let i = 0,len = s.length, mid = Math.floor(len / 2); i < mid; i++) {
        if (s[i] !== s[len - i - 1]) {
            flag = false;
        }
    }
    return flag;
};
```