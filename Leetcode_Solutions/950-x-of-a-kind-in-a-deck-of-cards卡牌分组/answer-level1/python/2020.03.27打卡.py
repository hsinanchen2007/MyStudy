### 解题思路
计数器，最大公因子>=2

### 代码

```python3
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        dico = collections.Counter(deck)
        dl = list(dico.values())
        if len(dl) == 1 and dl[0] < 2: return False
        for i in range(0, len(dl) - 1):
            for j in range(i+1, len(dl)):
                if gcd(dl[i], dl[j]) < 2: return False
        return True
        
```