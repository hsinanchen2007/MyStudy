```python
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
		return haystack.find(needle)
```
- 不用内置函数也可以
```python
 class Solution:
 	def strStr(self, haystack: 'str', needle: 'str') -> 'int':
 	    for i in range(0, len(haystack) - len(needle) + 1):
 	        if haystack[i:i+len(needle)] == needle:
 	            return i
     	return -1
```