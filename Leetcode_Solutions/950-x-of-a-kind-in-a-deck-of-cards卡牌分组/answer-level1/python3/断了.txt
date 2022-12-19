### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        a = collections.Counter(deck)
        N = len(deck)
        ###x==N是只分一种
        for x in range(2,N+1):
            if N % x == 0:
                if all(v%x==0 for v in a.values()):
                    return True
        return False
```