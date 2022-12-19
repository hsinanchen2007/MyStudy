```
class Solution:
    def isSubsequenceFast(self, s: str, t: str) -> bool:
        # 迭代器保证t的顺序
        b = iter(t) 
        # (w for w in s): 生成器, 节省内存空间
        for i in (w for w in s):
            if not i in b:
                return False
        return True
    def isSubsequenceSlow(self, s: str, t: str) -> bool:
        # 迭代器保证t的顺序
        b = iter(t) 
        # all: 均为True返回True
        return all(w in b for w in s)
```
