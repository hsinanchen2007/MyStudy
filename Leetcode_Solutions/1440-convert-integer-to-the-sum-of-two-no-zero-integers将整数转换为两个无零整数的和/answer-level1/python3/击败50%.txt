```
class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        num1 = 0
        num2 = 0
        while "0" in str(num1) or "0" in str(num2):
            num1 += 1
            num2 = n - num1
        return(num1,num2)
            
```
