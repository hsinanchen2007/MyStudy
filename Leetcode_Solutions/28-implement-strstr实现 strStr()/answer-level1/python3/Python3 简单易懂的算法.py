### 解题思路
执行用时 :32 ms, 在所有 Python3 提交中击败了90.77%的用户

### 代码

```python3
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        """
        使用Python的 str in str的功能已经string.split
        """
        if not needle:
            return 0
        if needle in haystack:
            return len(haystack.split(needle)[0]) 
        return -1

```