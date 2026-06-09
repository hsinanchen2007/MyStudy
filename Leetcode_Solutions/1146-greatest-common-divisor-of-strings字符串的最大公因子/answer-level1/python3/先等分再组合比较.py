### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        longer = max(len(str1), len(str2))
        shorter = min(len(str1), len(str2))

        for i in range(min(len(str1), len(str2)), 0 , -1):
            if len(str1) % i != 0 or len(str2) % i != 0:
                continue
            if str1[:i] * (len(str1) // i) == str1 and str1[:i] * (len(str2) // i) == str2:
                return str1[:i]
        return ""

```