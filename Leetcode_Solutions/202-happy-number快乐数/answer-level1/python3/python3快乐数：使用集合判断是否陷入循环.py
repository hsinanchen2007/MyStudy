使用集合s判断当前和是否曾求出过，以跳出循环。
```
class Solution:
    def isHappy(self, n: int) -> bool:
        s={1}
        while n not in s:
            s.add(n)
            res=0
            while n>9:
                res+=(n%10)**2
                n//=10
            res+=n**2
            n=res
        return n==1
```
![image.png](https://pic.leetcode-cn.com/fc0fbc309eeba4ed95daacd63ae7623b64ff5a2659de6355a17a2c15e8f76daf-image.png)
