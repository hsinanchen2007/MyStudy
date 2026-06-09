暴力思路, 模拟判断过程
```
class Solution:
    def sumOfDigits(self, A: List[int]) -> int:
        num = min(A)
        res = 0
        for i in str(num):
            res+= int(i)
        return 1 if res%2==0 else 0
```
