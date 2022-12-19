### 解题思路
 1. 用两个指针，分别指向字符串的头尾节点
 2. 如果头尾相等则 l++, r--，执行完后如果 r <= l, 则说明 s 是回文字符串，返回 true
 3. 否则说明 s 不是回文字符串，此时我可以删除一个头节点的字符，或者尾节点的字符，再对其进行检测是否是回文字符串
 4. 因为只能删一个字符，所以我们只能删一次，可以使用一个 flag 进行过滤

### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var validPalindrome = function(s, flag = true) {
    let l = 0, r = s.length - 1;
    while (l < r && s[l] === s[r]) l++, r--;
    if (r <= l) return true;
    if (flag == true) return validPalindrome(s.slice(l, r), false) || validPalindrome(s.slice(l + 1, r + 1), false)
    return false;
};
```