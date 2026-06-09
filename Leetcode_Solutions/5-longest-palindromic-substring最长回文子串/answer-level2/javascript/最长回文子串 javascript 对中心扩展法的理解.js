执行用时 :96 ms, 在所有 javascript 提交中击败了92.77%的用户;

看完了评论还有官方的解释，说一下我对中心扩展法的理解：

官方说的是：
 我们观察到回文中心的两侧互为镜像。因此，回文可以从它的中心展开，并且只有 2n−1 个这样的中心。

为什么中心是2n-1而不是n ? 比如有字符串abcba，这时回文子串是abcba，中心是c；

 又有字符串adccda，这时回文子串是adccda，中心是cc。 

 由此可见中心点既有可能是一个字符，也有可能是两个字符，当中心为一个字符的时候有n个中心，当中心为两个字符的时候有n-1个中心，所以一共有2n-1个中心。

1. 考虑字符串长度为0和1的情况；
2. 考虑字符串长度为2的情况，若为2则判断这个字符串是不是回文字符串；
3. `for`循环字符串，比较第`i`项和第`i+1`项是否相同(`s[i]`是否等于`s[i+1]`)；
4. 若是相同则表示`s[i] + s[i+1]`为偶数的回文中心，因此应该继续比较`i-1`和`i+2`项；比如给定字符串`abba`，`i`为`1`时，我们已经知道了`s[i] + s[i+1]`，此时应该以`bb`为中心向左右进行扩展比较`s[i-1]`和`s[i+2`]项；
5. 若是不同则表示字符串可能是为寄数的回文中心，因此应该以`s[i]`为中心向左右进行扩展比较`s[i-1]`和`s[i+1]`项；
6. 每次`for`循环中比较上面得到的寄数回文字符串和偶数回文字符串，取较长的；
7. 每次`for`循环中比较之前记录下最长的回文字符串和这次的回文字符串，取较长的；
8. `for` 循环之后即可得到最长回文字符串；

中心扩展法的核心就是通过找到回文中心，然后以该中心向左右两边扩展来查找。

```javascript
/**
* @param {string} s
* @return {string}
*/
var longestPalindrome = function (s) {
    if (!s) return ''
    if (s.length === 1) return s;
    if (s.length === 2) return s[0] === s[1] ? s : s[1];
    let maxStr = '',
        len = s.length;
    for (let i = 0; i < len; i++) {
        let even = '', // 定义偶数中心回文
            odd = ''; // 定义奇数中心回文
        if (s[i] === s[i + 1]) { // 若是偶数中心回文
            let evenIndex = center(s, i - 1, i + 2); // 比较中心的前一项和后一项
            even = s.slice(evenIndex.left, evenIndex.right)
        }
        let oddIndex = center(s, i - 1, i + 1); // 奇数中心回文
        odd = s.slice(oddIndex.left, oddIndex.right);
        let longer = even.length > odd.length ? even : odd; // 比较奇、偶
        maxStr = maxStr.length > longer.length ? maxStr : longer
    }
    return maxStr
}
// 中心扩展
function center(s, left, right) {
    let len = s.length;
    while (left >= 0 && right < len && s[left] === s[right]) {
        left--;
        right++;
    }
    return { left: left + 1, right: right }
}
```
