### 解题思路
首先计算总和，判断是否可以三等分
然后计算是否刚好有三部分等于总和//3

### 代码

```python3
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        if len(A)<3:
            return False

        ans = sum(A)
        if ans%3:
            return False
        else:
            r = ans//3
            s = 0
            tmp = 0
            for i in range(len(A)):
                if tmp==3:
                    break
                if tmp==2:
                    s = sum(A[i:])
                else:
                    s += A[i]

                if s==r:
                    s = 0
                    tmp+=1
        
        return tmp==3
```