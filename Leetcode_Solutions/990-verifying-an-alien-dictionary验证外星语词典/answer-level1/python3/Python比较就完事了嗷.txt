### 解题思路
legal函数用于返回比较的两个字符串是否符合order的要求，再在words列表中两两比较。

### 代码

```python3
class Solution:
    def legal(self, s1: str, s2: str, order: str) -> bool:
        i, j = 0, 0
        while i < len(s1) and j < len(s2):
            t1, t2 = 0, 0
            for k in range(len(order)):
                if order[k] == s1[i]:
                    t1 = k
                if order[k] == s2[j]:
                    t2 = k
            if t1 < t2:
                return True
            elif t1 > t2:
                return False
            else:
                i += 1
                j += 1
        return len(s1) < len(s2)

    
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        for i in range(1, len(words)):
            if not self.legal(words[i - 1], words[i], order):
                return False
        return True
```