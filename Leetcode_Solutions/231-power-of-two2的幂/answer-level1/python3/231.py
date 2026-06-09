### 解题思路
1、处理特殊情况：n<=0返回False；
2、循环判断，n==1则返回True；n%2!=0直接返回False，否则n=n//2。

### 代码

```python3
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n <= 0:
            return False
        while n > 0:
            if n == 1:
                return True
            if n % 2 == 0:
                n = n // 2
            else:
                return False
```