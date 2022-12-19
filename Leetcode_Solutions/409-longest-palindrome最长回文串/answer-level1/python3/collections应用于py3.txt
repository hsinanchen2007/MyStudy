### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        c=collections.Counter(s).values()
        return 2*sum(i//2 for i in c)+any(i%2 for i in c)
```