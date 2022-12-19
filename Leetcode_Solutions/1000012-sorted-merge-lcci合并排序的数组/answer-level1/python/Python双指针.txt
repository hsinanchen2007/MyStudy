### 解题思路
此处撰写解题思路
双指针：p、q分别指向A、B末尾
依次将两者较大的一方，加入到A的末尾，向前移动指针
当有q指向B第一个元素时结束或者p指向A第一个元素时，将A前面的元素替换为B剩下的元素

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
        p = len(A)-1
        while m > 0 and n > 0:
            A[p] = A[m-1] if A[m-1] > B[n-1] else B[n-1]
            if A[p] == A[m-1]:
                m -= 1
            else:
                n -= 1
            p -= 1
        if m == 0:
            for i in range(n):
                A[i] = B[i]

```