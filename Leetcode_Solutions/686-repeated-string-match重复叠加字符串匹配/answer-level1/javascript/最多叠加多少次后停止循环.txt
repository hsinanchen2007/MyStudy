## 第一版
> 64ms,35.7M。
```javascript []
/**
 * @param {string} A
 * @param {string} B
 * @return {number}
 */
var repeatedStringMatch = function(A, B) {
  const endLen = B.length + A.length * 2;
  for (let count = 1, repeatA = A; repeatA.length <= endLen; count++, repeatA += A) {
    if (repeatA.includes(B)) return count;
  }
  return -1;
};
```
#### 思路
- 话说官方题解的描述看起来有些复杂而且不够直观，其他题解大多也都提到了关键是要找到终止长度即`B.length + A.length * 2`，我尝试说明一下原因。
- 在`B`的长度大于`A`长度时且能够满足题意`A`叠加后`B`成为其子串的，总共只有四种情况
    1. 叠加`n`个`A`后刚好与`B`完全相等，例如`A = 'ab', B = 'abab'`，此时刚好只需要循环`n`次即可满足条件，循环更多次也只是重复无用功
    2. 叠加`n`个`A`后与`B`的后部分完全相等，但此时`B`头部还有一小部分值刚好是`A`尾部分，例如`A = 'ab', b = 'babab'`，此时最少需要循环`n + 1`次才可满足条件
    3. 同上一条，但多余部分出现在`B`的尾部，例如`A = 'ab', b = 'ababa'`，此时最少需要的循环次数同上
    4. 同上，多余部分在`B`的头尾都有，例如`A = 'ab', b = 'bababa'`，此时最少需要的循环次数为`n + 2`次
- 由上面的所有情况分析得到最少需要循环的次数为`n + 2`次，`n`为正整数，转化为最小需要的长度S就是`S >= (n + 2) * A.length`，因为`n = B.length / A.length`，所以`S >= B.length + A.length * 2`
#### 判断条件可优化
> 60ms,35.6M。

`if (repeatA.includes(B)) return count;`
改为
`if (repeatA.length >= B.length && repeatA.includes(B)) return count;`