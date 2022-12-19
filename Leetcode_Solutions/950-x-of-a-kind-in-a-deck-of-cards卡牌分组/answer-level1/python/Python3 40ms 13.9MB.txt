### 解题思路
1. counter统计
2. 求所有数的的最大公约数
3. 判断求得的最大公约数是否等于等于2

### 代码

```python3
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        deck_values = collections.Counter(deck).values()
        X = min(deck_values)
        for i in deck_values:
            X = math.gcd(X, i)
        return X>1
```