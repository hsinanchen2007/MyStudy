### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        tmp=[i if i.isdigit() else i.lower() for i in s if i.isalpha() or i.isdigit()]
        return tmp==tmp[::-1]
```