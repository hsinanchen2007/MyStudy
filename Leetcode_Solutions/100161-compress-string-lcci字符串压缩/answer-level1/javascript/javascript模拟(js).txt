思路

字符串压缩的方式就是将连续出现的相同字符按照 字符 + 出现次数 压缩。如果压缩后的字符串长度变短，则返回压缩后的字符串，否则保留原来的字符串，所以我们模拟这个过程构建字符串即可。

算法

我们从左往右遍历字符串，用 chch 记录当前要压缩的字符，\textit{cnt}cnt 记录 chch 出现的次数，如果当前枚举到的字符 s[i]s[i] 等于 chch ，我们就更新 \textit{cnt}cnt 的计数，即 cnt = cnt + 1，否则我们按题目要求将 chch 以及 \textit{cnt}cnt 更新到答案字符串 \textit{ans}ans 里，即 ans = ans + ch + cnt，完成对 chch 字符的压缩。随后更新 chch 为 s[i]s[i]，cntcnt 为 11，表示将压缩的字符更改为 s[i]s[i]。

在遍历结束之后，我们就得到了压缩后的字符串 \textit{ans}ans，并将其长度与原串长度进行比较。如果长度没有变短，则返回原串，否则返回压缩后的字符串。

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var compressString = function(S) {
    if (!S) {
        return S;
    }
    let str = '';
    let val = S[0];
    let count = 1;
    const len = S.length;
    for (let i = 1; i < len; i++) {
        if (S[i] !== val) {
            str += val + count;
            val = S[i];
            count = 1;
        } else {
            count++;
        }
    }
    str += val + count;
    return (str.length < len) ? str : S;
};
```