### 解题思路
#排序
1.从数组A和数组B的末端元素开始逐个比较，将更大的元素放入A中相应下表的位置中；
2.若B中元素比较完了，不需要任何操作；
3.若A中元素比较完了，将B中剩下的元素接入到A后面即可。
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
        i, j = m-1, n-1
        l = m + n - 1
        while i >=0 and j >= 0:
            if A[i] > B[j]:
                A[l] = A[i]
                i -= 1
            else:
                A[l] = B[j]
                j -= 1
            l -= 1
        while j >= 0:
            A[l] = B[j]
            l -= 1
            j -= 1
        

       

        
        
```