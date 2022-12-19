### 解题思路
双指针，一个从前往后，一个从后往前

### 代码

```python3
class Solution:
    def isPalindrome(self, s: str) -> bool:
        i, j = 0, len(s) - 1
        s = s.lower()
        while i <= j:
            if not s[i].isalnum():
                i += 1
                continue
            if not s[j].isalnum():
                j -= 1
                continue
            if not s[i] == s[j]:
                return False
            i += 1
            j -= 1
        return True
```