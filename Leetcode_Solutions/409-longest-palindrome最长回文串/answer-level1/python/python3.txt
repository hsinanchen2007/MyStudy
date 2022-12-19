### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        return len(s) -max(0,sum([s.count(i)%2 for i in set(s)])-1)



    
```