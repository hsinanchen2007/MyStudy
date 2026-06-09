### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def addToArrayForm(self, A: List[int], K: int) -> List[int]:
        car=0
        i=len(A)-1
        while i>=0:
            car,A[i] = divmod(A[i]+K%10+car,10)
            i-=1
            K//=10
        if K==0:
            if car ==0:
                return A
            else:
                res=[car]
                res.extend(A)
                return res
        else:
            K+=car
            res=[]
            while K>0:
                res.insert(0,K%10)
                K//=10
            res.extend(A)
            return res
```