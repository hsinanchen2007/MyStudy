### 解题思路
迭代，感觉自己对python的传值和传引用还不是很了解

### 代码

```python3
class Solution:
    def countAndSay(self, n: int) -> str:
        a=[1]
        if n==1:
            return str(1)
        for i in range(n-1):
            a=self.DD(a)
        s=""
        for i in a:
            s=s+str(i)
        return  s
        

    def DD(self,a:list):
        Now = a[0]
        c=a
        a.append(-1)
        b = []
        num = 0
        for i in c:
            if i == Now:
                num += 1
            else:
                b.append(num)
                b.append(Now)
                Now = i
                num = 1
                a = b
        return a

    
```