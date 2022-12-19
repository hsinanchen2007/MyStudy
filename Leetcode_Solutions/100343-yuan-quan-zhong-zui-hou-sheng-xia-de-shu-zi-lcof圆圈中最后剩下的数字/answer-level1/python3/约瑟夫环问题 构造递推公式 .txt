函数circle(n,m)表示共n个人，以m为次序叫号，最终留下的那个人的index.
circle(n-1,m)表示共n-1个人，以m为次序叫号，最终留下的那个人的index.
反向递推之后即可得答案。
```python []
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        def circle(n,m):# n people , m sequence
            if n==1:
                index=0
            else:
                index=(circle(n-1,m)+m)%n
            return index
        return circle(n,m)
```

