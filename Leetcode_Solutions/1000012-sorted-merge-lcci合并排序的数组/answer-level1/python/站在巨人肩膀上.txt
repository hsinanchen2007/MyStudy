### 解题思路
1. 既已告知A的有效数据数量，只需在其后将B数据填入即可
2. 利用列表的方法**list.sort()**来进行排序

**迷思**：既然是面试题，可能会对时空复杂度提出要求? 看看别人题解


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
        for i in B:
            A[m]=i
            m+=1
        A.sort()
        return A
```