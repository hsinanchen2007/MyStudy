```
class Solution(object):
    def flipAndInvertImage(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        return [[x^1 for x in a[::-1]] for a in A]
```             
这里记录一下a[::-1]：
可以理解为a[start:end:span]的简便写法，start 不输入则默认为 0，end 不输入默认为长度。遍历 [start,end)，间隔为 span，当 span>0 时顺序遍历, 当 span<0 时，逆序遍历。

