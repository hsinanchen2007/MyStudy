### 解题思路
思路很简单：collections.Counter()把每个元素和其对应的个数对应到一个字典里
然后循环找每个元素个数的公约数，如果每个个数都有比2大的公约数就return Ture

### 代码

```python3
class Solution:
    def hasGroupsSizeX(self, deck) -> bool:
        count = collections.Counter(deck)
        n = len(deck)
        for i in range(2,n + 1):
            if n % i == 0:
                if all( j % i == 0 for j in count.values()):
                    return True
        return False
```