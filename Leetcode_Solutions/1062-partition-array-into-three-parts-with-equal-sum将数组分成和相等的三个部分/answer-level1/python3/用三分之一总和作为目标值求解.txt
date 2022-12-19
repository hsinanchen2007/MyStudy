### 解题思路
累计求和，找到和为三分之一的即为第一组，接着继续找第二组，剩余的即为第三组

### 代码

```python3
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        n=len(A)       
        if n<3:
            return False
        sums=sum(A)
        target=1/3*sums
        sum1=0
        for i in range(0,n-2):
            sum1+=A[i]
            if sum1==target:
                sum2=0
                for j in range(i+1,n-1):
                    sum2+=A[j]
                    if sum2==target:
                        return True
        return False
```