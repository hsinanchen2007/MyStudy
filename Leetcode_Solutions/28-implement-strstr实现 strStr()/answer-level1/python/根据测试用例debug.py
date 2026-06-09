### 解题思路
没话说。交一个错一个，根据用例debug
### 代码
```python
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if not needle:return 0
        if not haystack:return -1
        for i in range(len(haystack)):
            ind = 0
            if haystack[i]==needle[ind]:                
                while ind < len(needle):
                    if i + ind >= len(haystack):return -1
                    if haystack[i+ind] == needle[ind]: ind += 1
                    else:break
                    if ind == len(needle):return i
        return -1
```