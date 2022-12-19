```
import math
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        nums = [i + 1 for i in range(n)]
        rst = []
        for i in range(n):
            if k==1:
                rst+=nums
                break
            if k==0:
                rst+=nums[::-1]
                break
            tf = math.factorial(n-1-i)
            cur = (k-1)//tf
            k=k%tf
            rst.append(nums.pop(cur))

        return ''.join(map(lambda x:str(x), rst))
```
