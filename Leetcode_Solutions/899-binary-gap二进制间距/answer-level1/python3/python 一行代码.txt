```python
class Solution:
    def binaryGap(self, N: int) -> int:
        return 0 if (N-1)&N==0 else max(len(s) for s in bin(N)[2:].strip('0').split('1'))+1
```
(N-1)&N==0 是判断 只有一个1或者 N为0 的时候