### 解题思路
try

### 代码

```python3
class Solution:
    def m(self,n):
        if n==1:
            return 1
        else:
            sum=0
            for i in str(n):
                sum+=int(i)**2
            return sum
    def isHappy(self, n: int) -> bool:
        test =[]
        while True:
            k = self.m(n)
            if k == 1:
                return True
            else:
                if n not in test:
                    test.append(n)
                    n = self.m(n)
                    print(n)
                else:
                    return False
        return False
```