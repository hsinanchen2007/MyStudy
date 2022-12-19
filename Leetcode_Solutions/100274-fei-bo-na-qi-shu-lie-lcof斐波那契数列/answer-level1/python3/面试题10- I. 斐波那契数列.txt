### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def fib(self, n: int) -> int:
        f0=0
        f1=1
        if n==0:
            return 0
        elif n==1:
            return 1
        else:
            for _ in range(n-1):
                f1, f0 = (f1+f0)%1000000007, f1
            return f1
```