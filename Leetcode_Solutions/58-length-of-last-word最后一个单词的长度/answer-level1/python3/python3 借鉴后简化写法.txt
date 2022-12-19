### 解题思路
话不多说，直接上代码


### 代码

```python3
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        return len(s.strip(' ').split(' ')[-1])
```