```
class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        import collections
        count = collections.Counter(bin(n)).get("1")
        return count if count else 0
```
注意字典无该key时返回None，我们函数需要返回0

当然似乎有点多余，string的count()函数也可以返回该字符的个数，