```python
class Solution:
    def isHappy(self, n: int) -> bool:
        dic = collections.defaultdict(int)
        while n!=1:
            n = sum([int(i)**2 for i in str(n)])
            dic[n]+=1
            if dic[n]>1:return False
        return True
```