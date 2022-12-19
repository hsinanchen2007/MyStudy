### 解题思路
内置函数解法(既然是解算法题，如果直接用现成的算法来解决而不是自己实现算法解决，有多大意义呢？)

### 代码

```python3
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        a,b=int(a,2),int(b,2)
        res=bin(a+b)
        res=str(res)[2:]
        return res
```