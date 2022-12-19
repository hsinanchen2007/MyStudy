### 解题思路

``数组`` 里的最小值是 $0$，最大值是 $N$，题目要求：

- 如果 ``S[i] == "I"``，那么 ``A[i] < A[i+1]``
- 如果 ``S[i] == "D"``，那么 ``A[i] > A[i+1]``

那么思路很简单，碰到 ``"I"`` 就从最小值开始填充，碰到 ``"D"`` 就从最大值开始填充即可。

### 代码

```javascript
/**
 * @param {string} S
 * @return {number[]}
 */
var diStringMatch = function(S) {
    let N = S.length
    let i = 0
    let max = N
    let min = 0
    let res = []
    while (i <= N) {
        if (S.charAt(i) === 'I') {
            res.push(min++)
        } else {
            res.push(max--)
        }
        i++
    }
    return res
};
```