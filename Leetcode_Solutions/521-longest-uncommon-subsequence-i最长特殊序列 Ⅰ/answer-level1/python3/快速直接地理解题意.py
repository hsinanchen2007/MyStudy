快速直接理解题意：
    - 找到两个字符串彼此不相同的最长的长度
    - 那么只要两个字符串本身不同，答案即为两者较长的那一个
```python
class Solution(object):
    def findLUSlength(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: int
        """
        if a == b:
            return -1
        return max(len(a), len(b))
```