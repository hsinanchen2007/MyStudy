### 解题思路
遍历字符串，遇到‘L’减1，遇到‘R’加1，和为0时，记为一个平衡字符串。

### 代码

```python3
class Solution:
    def balancedStringSplit(self, s: str) -> int:
        ans = 0
        n = 0
        for i in s:
            ans = ans-1 if i == 'L' else ans+1
            if ans == 0: n += 1
        return n

```