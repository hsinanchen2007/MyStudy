
```
def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        # 类似 插入排序
        for i in range(n):
            temp = B[i]
            index = m+i   # 注意这里
            while index >= 1 and A[index-1] > temp:
                A[index] = A[index-1]  
                index = index - 1
            A[index] = temp
        return A
```
