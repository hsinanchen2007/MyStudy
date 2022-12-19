最后那个if语句的几个and连接的语句的顺序挺重要的。
```
class Solution:
    def selfDividingNumbers(self, left, right) :
        ans = []
        for i in range(left, right + 1):
            tmp = i
            tmp, re = tmp // 10, tmp % 10
            while (tmp > 10 and re != 0 and i % re == 0):
                tmp, re = tmp // 10, tmp % 10
            if i<10:
                ans.append(i)
            else:
                if tmp and re and i%re==0 and i % tmp == 0:
                    ans.append(i)
        return ans
```

