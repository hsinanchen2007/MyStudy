### 解题思路
暴力法
偶数、奇数分开，最后各自排序，偶数加在奇数前面就行。
### 代码

```python3
class Solution:
    def sortArrayByParity(self, A: List[int]) -> List[int]:
        b=[]
        c=[]
        for i in range(len(A)):
            if A[i]%2==0:
                b.append(A[i])
            else:
                c.append(A[i])
        b.sort()
        c.sort()
        return b+c
```