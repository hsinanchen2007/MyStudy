### 解题思路
本题目的标签是双指针，思考了半天双指针应该怎么写？
不知道这个代码算是双指针吗？
### 代码

```python3
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        for i in range(len(haystack) - len(needle) + 1):
            if haystack[i:i + len(needle)] == needle:
                return i
        return -1
                
```