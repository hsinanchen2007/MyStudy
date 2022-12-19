### 解题思路
做法就是在线性时间用双数组先把对应的乘数都计算出来

### 代码

```python3
class Solution:
    def constructArr(self, a: List[int]) -> List[int]:
        C = [1 for _ in range(len(a))]
        D = [1 for _ in range(len(a))]
        B = [None for _ in range(len(a))]
        for i in range(1,len(a)):
            C[i] = C[i-1] * a[i-1]
        
        for i in reversed(range( len(a)-1 )):
            D[i] = D[i+1] * a[i+1]
            
        for i in range(len(a)):
            B[i] = C[i] * D[i]
            
        return B
```