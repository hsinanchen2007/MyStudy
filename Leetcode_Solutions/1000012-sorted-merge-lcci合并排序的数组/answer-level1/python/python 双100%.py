###成绩
执行结果：
通过
显示详情
执行用时 :
16 ms
, 在所有 Python 提交中击败了
100.00%
的用户
内存消耗 :
11.7 MB
, 在所有 Python 提交中击败了
100.00%
的用户

### 解题思路
此处撰写解题思路

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
        if n==0 and m==0: return A
        l = []
        p = 0
        for i in range(n):
            while B[i] > A[p] and p<m:
                l.append(A[p])
                p += 1
            l.append(B[i])
        if p<m:
            l.extend(A[p:m])
        for i in range(len(l)):
            A[i] = l[i]
```