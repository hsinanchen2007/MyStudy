### 解题思路
通过循环来对A进行赋值，将B的值逐步赋值给A，后面的排序使用python自带函数
### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        for i in range(len(B)):
            A[m+i] = B[i]
        A.sort()



```