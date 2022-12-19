### 解题思路
直接递归会有很多重复计算，查个表避免重复计算。
f(n)=f(n-1)+f(n-2)

解释：比如在第n步，那么要么是从n-1阶上来的，要么是从n-2阶上来的。
其实这个和斐波那契数列一致。

### 代码

```python3
class Solution:
    def __init__(self):
        self.dic=dict()
        self.dic[0]=1
        self.dic[1]=1
    def climbStairs(self, n: int) -> int:
        if n in self.dic:return self.dic[n]

        if n-1 in self.dic:
            n_1=self.dic[n-1]
        else:
            n_1=self.climbStairs(n-1)
            self.dic[n-1]=n_1
        if n-2 in self.dic:
            n_2=self.dic[n-2]
        else:
            n_2=self.climbStairs(n-2)
            self.dic[n-2]=n_2

        return n_1+n_2
```

```
        c=a=b=1
        count=1
        while count!=n:
            c=a+b
            a=b

            b=c
            count+=1
        return c
```
