# note
工程上可能会这么写，面试的时候如果这么搞，估计被怼~~慎重~~

# 代码
```
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        return str(bin(int(a, 2) + int(b, 2)))[2:]
```