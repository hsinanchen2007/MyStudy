### 代码

```python
class Solution(object):
    def printNumbers(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        NumList=[]
        k=1
        m=0
        while m<n:
            k=k*10
            m+=1
        for i in range(1,k):
            NumList.append(i)
        return NumList
```