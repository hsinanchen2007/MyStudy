### 解题思路
先将x转换成list，再使用list.reverse()反向排序，如果反向后的list等于原始的list就返回True

### 代码

```python
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        res = list(str(x))
        res.reverse()
        return list(str(x))==res
```