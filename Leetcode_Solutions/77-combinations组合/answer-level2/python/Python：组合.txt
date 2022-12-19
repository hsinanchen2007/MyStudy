### 解题思路
不是算法……
又学习了一遍迭代器，真好

### 代码

```python3
import itertools
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        return list(itertools.combinations(range(1,n+1),k))
```