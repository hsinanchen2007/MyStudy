### 代码1

```python3
class Solution:
    def canWinNim(self, n: int) -> bool:
        return not n%4 == 0
```

### 代码2
我觉得这个方法思路上是没错误的，但显然超时了

```python3
class Solution:
    def canWinNim(self, n: int) -> bool:
        if n in [1, 2, 3]:
            return True
        
        # 对方一定赢 则res是True
        res = self.canWinNim(n-1) and self.canWinNim(n-2) and self.canWinNim(n-3)
        
        return not res
```