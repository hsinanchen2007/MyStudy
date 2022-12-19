### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def wordPattern(self, pattern: str, str: str) -> bool:
        if len(str.split(" ")) != len(list(pattern)):
            return False
        for l in zip(*set(zip(list(pattern), str.split(" ")))):
            if len(l) != len(set(l)):
                return False
        return True

```