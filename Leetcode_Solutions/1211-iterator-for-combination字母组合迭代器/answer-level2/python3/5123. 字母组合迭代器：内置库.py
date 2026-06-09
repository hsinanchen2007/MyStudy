### 解题思路
直接组合输出，并且求出组合数，或者直接转成数组，判断判断存在

### 代码

```python []
class CombinationIterator:

    def __init__(self, characters: str, combinationLength: int):
        self.d = itertools.combinations(characters, combinationLength)
        self.n = math.comb(len(characters), combinationLength)

    def next(self) -> str:
        self.n -= 1
        return ''.join(next(self.d))

    def hasNext(self) -> bool:
        return self.n
```
```python []
class CombinationIterator:

    def __init__(self, characters: str, combinationLength: int):
        self.d = collections.deque(itertools.combinations(characters, combinationLength))

    def next(self) -> str:
        return ''.join(self.d.popleft())

    def hasNext(self) -> bool:
        return self.d
```

![image.png](https://pic.leetcode-cn.com/1b434ab8774dbaee0c1776adb114e1d55d1bae0142f13c03d3d19f562ec276af-image.png)

