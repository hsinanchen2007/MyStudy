### 解题思路
此处撰写解题思路
按顺序将B插入，找到A中比B[i]大的j，在此位置插入B[i]，如果j已经到了末尾，就将B直接插入到A就好了

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
        j = 0
        for i in range(n):
            while A[j] < B[i] and j < m:
                j += 1
            
            if j >= m:
                A[j:] = B[i:]
                break
            else:
                A[j+1:m+1] = A[j:m]
                A[j] = B[i]
                m += 1
                j += 1
        return A
```