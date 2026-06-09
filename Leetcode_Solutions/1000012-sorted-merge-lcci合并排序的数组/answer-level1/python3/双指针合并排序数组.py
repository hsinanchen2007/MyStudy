**双指针法**
```
1. 开辟一个新的list(temp)
2. 将A，B中的元素按从小到大添加到temp中，注意边界的确定
3. 将list中的元素覆盖A中的元素，注意A[:] = temp 与 A = temp 的区别，A = temp将两者指向同一个对象
而A[:] = temp会创建一个新的与temp完全相同的对象，但是与temp并不指向同一对象

代码块
```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        temp = []
        pa,pb = 0,0
        while pa < m or pb < n:
            if pa == m:
                temp.append(B[pb])
                pb += 1
            elif pb == n:
                temp.append(A[pa])
                pa += 1
            elif A[pa] > B[pb]:
                temp.append(B[pb])
                pb += 1
            elif A[pa] < B[pb]:
                temp.append(A[pa])
                pa += 1
            else:
                temp.append(B[pb])
                pb += 1
        A[:] = temp
