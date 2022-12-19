### Step1.分析题意

问给定数组$A$能否分成和相等的三部分。

### Step2.前缀和

考虑求数组$A$的前缀和。求完之后：

1. 若$A[n]$不是3的倍数，返回$False$；
2. 若$A[1:n]$（注意$Python\ List$的截取是左闭右开）包含$i<j$且$A[i]=A[n]/3$，$A[j]=A[n]/3*2$，返回$True$，否则返回$False$。

```python3
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        n = len(A)
        
        A.insert(0, 0)
        for i in range(1, n + 1): A[i] += A[i - 1]
        
        if A[n] % 3 != 0: return False
        
        flag1, flag2 = False, False
        for a in A[1: n]:
            if flag1 == True and a == A[n] // 3 * 2: flag2 = True
            elif a == A[n] // 3: flag1 = True
        return flag1 and flag2
```