### 解题思路


### 代码

```python
class Solution(object):
    def sumOfDigits(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        x = min(A)
        
        if 10<x<100:
            return int((x%10 + x/10)%2==0)
        else:
            return int(x%2==0)




        












```