### 解题思路
A和B的下标做循环变量，B如果小于A，B插入A，否则A下标后移，最后如果B有剩余，插到A后面

### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """

        i=0
        j=0
        r = m
        while r > 0 and j<n:
            # print(i,j,r)
            if B[j]<= A[i]:
                A[i+1:i+1+r] =A[i:i+r]
                A[i]=B[j]
                j+=1
                i+=1
                
            else:
                i += 1
                r-=1
        if j<n:
            A[i:]=B[j:]
```