### 解题思路
避免【-1,1,-1,1】需要开始时就把两边加上 不至于两个计数器和0相同
### 代码

```python3
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        s = sum(A)
        if s % 3 != 0:
            return False
        target = s // 3
        i,j=1,len(A)-2
        left,right=0,0
        left=left+A[0]
        right=right+A[-1]
        while i<=j:
            if left!=target:
                left=left+A[i]
                i=i+1
            elif right!=target:
                right=right+A[j]
                j=j-1
            elif right==left and right==target:
                return True
            else:
                i=i+1
                j=j-1
        return False
            
```