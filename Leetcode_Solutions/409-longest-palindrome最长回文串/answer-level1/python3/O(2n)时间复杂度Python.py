### 解题思路
先对每个字母计数，数目为偶数的字母全部加到回文串里，数目为奇数的字母分情况，如果数目大于等于3，数目-1就是偶数个，可以加到回文串里，最后结果再加1，因为有奇数的回文串最中间的字母个数肯定是奇数。

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        ans = collections.Counter(s)
        count = 0
        L = []
        for i in ans:
            if ans[i] % 2 == 0:
                count += ans[i]
            if ans[i] % 2 == 1:
                L.append(ans[i])
        if not L:
            return count
        for x in L:
            if x >=3:
                count += x-1
        return count+1




```