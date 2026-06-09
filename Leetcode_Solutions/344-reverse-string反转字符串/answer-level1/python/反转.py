### 解题思路
搞了半天才知道参数要在def里面直接改掉...
s[::-1]就是反转了 还是简单的

### 代码

```python
class Solution(object):
    def reverseString(self, s=["h","e","l","l","o"]):
        """
        :type s: List[str]
        :rtype: None Do not return anything, modify s in-place instead.
        """
        s[:] = s[::-1]
        # print()
```