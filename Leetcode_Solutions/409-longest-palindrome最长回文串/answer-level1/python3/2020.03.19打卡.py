### 解题思路
判断元素出现频数的奇偶性，并作出相应的处理。

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        dico = collections.Counter(s)
        ans = 0
        judge = 0
        for i, j in dico.items():
            if not j % 2:
                ans += j
            else:
                ans += j-1
                judge = 1
        return ans + judge
```