### 解题思路
先将B中的元素合并到A中，再对A进行排列，python3直接调用sort()方法可以在原列表进行更改，实现对原列表的排序，不返回任何值

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
        A[m:] = B
        A.sort()
```