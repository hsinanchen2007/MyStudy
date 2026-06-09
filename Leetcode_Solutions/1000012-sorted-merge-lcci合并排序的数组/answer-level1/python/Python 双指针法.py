### 解题思路
双指针法很简单，不再赘述，需要注意的是，这里需要从后往前遍历，否则需要移动元素，而且这里循环条件可以让程序提前退出，因为如果B中的数组用完了说明剩下的就是A中的元素不需要继续遍历。

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
        i = len(A) - 1
        p, q = m - 1, n - 1
        while q > -1:
            if q < 0 or p >= 0 and A[p] > B[q]:
                A[i] = A[p]
                p -= 1
            else:
                A[i] = B[q]
                q -= 1
            i -= 1
        
        
```