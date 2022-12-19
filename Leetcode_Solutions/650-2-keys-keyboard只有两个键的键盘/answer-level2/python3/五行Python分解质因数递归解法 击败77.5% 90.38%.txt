n个'A'的解=n的最大因数的解+n//n的最大因数

![image.png](https://pic.leetcode-cn.com/3f09945f840ad3558ee87a695505c1c84e4e8e70db0951fde37d477fcdb3bda4-image.png)

```
class Solution(object):
    def minSteps(self, n):
        if(n==1):
            return 0
        for i in range(n//2,0,-1):
            if(n%i==0):
                return self.minSteps(i)+n//i
            
sol=Solution()
print(sol.minSteps(7))
```
