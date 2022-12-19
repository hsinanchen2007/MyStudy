### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """

        return (True if str(x) == str(x)[::-1] else False)
        
```