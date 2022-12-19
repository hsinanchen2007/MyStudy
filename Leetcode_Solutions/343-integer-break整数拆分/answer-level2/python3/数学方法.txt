### 解题思路
主要是sum(a+b)一定时，max(a*b)一定时diff(a,b)最小的时候。
而易得仅当a,b < 2时,a+b > a*b , if diff(a,b)->0

设n = n1+n2,而此时的n1>=4, 则n1*n2 <= (n1'+n1'')*n2
意思就是如果可拆则继续拆，当且仅当n'={2,3}则结束拆分
### 代码

```python3
class Solution:
    def integerBreak(self, n: int) -> int:
        if n == 2:
            return 1
        if n == 3:
            return 2
        
        if n%3 == 0:
            return 3**(n//3)
        elif n%3 == 1:
            return 3**(n//3 - 1)*4
        elif n%3 == 2:
            return 3**(n//3)*2

```