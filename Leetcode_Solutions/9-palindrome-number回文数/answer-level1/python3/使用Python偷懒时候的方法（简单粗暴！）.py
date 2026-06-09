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
        x = str(x)
        return(x == x[::-1])
```

简单粗暴的方法，直接变成字符串，然后判断即可。