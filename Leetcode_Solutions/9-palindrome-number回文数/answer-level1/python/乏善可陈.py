乏善可陈。

整道题目的代码如下：

```python
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        x = str(x)
        return (True if x == x[::-1] else False)
```