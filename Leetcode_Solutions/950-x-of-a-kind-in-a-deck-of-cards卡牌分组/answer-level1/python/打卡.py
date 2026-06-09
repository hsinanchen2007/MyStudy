### 解题思路
使用reduce调用列表中的元素

### 代码

```python3
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        l = collections.Counter(deck).values()
        return reduce(math.gcd, l) >=2
```