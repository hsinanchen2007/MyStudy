```
class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        res = []
        for i in range(left, right+1):
            ans = True
            if '0' in str(i): continue
            for j in str(i):
                if i%int(j) != 0: 
                    ans = False
                    break
            if ans:
                res.append(i)
        return res
```
