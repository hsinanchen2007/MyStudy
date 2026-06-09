### 解题思路
将两个list连接并排序，效果竟然还可以
执行用时 :20 ms, 在所有 Python 提交中击败了89.29%的用户
内存消耗 :11.9 MB, 在所有 Python 提交中击败了100.00%的用户
### 代码

```python
class Solution(object):
    def merge(self, A, m, B, n):
        """
        :type A: List[int]
        :type m: int
        :type B: List[int]
        :type n: int
        :rtype: None Do not return anything, modify A in-place instead.
        """
        i=m
        while B:
            A.remove(0)
            A.append(B.pop())
        A.sort()
        return A
```