### 解题思路
有多少個奇數個就減對應個數的1,最後+1

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        return len(s) -max(0,sum([s.count(i)%2 for i in set(s)])-1)
        
```