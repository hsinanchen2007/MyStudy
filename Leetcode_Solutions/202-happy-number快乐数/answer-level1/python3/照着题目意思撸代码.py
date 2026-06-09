此题关键在于如何在死循环中跳出循环
循环是无限的，但是每次平方和生成的数字是有限的，所以数字一定会重复，用字典保存每次新生成的数，一旦重复就跳出循环

```
    def isHappy(self, n: int) -> bool:
        dic=set()
        while True:
            res=0
            while n!=0:
                res+=(n%10)**2
                n=n//10
            if res==1:
                return True
            if res in dic:
                break
            dic.add(res)
            n=res
        return False
```
