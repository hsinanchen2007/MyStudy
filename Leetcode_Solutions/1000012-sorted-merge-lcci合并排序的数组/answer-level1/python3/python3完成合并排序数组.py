
第一种：python语言的特性，简洁清晰
```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        A[m:] = B[:n]
        A.sort()
```

第二种：
从m-1，n-1的位置，分别从A（从后往前第一个不为0的），B列表往前依次比较，较大的数字在A列表后边往前依次插入

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        while m>0 and n> 0:
            if A[m-1] >= B[n-1]:
                A[m+n-1] = A[m-1]
                m -= 1
            else:
                A[m+n-1] = B[n-1]
                n -= 1
        if n > 0:
            A[:n] = B[:n]
```

当出现 A = [7,8,9,0,0,0] , m = 3, B = [1,2,3] , n = 3 的测试用例时，
终止while循环后，A = [7,8,9,7,8,9],
所以需要 A[:n] = B[:n]
```python3
        if n > 0:
            A[:n] = B[:n]
```
