相对简单的写法


```python
from itertools import chain

class Solution:

    def construct(self, grid: List[List[int]]) -> 'Node':
        def helper(g):
            node = Node(g[0][0], True, None, None, None, None)
            n = len(g)

            if n == 1:
                return node

            is_leaf = True
            nums = set()

            for num in chain(*g):
                nums.add(num)
                if len(nums) > 1:
                    is_leaf = False
                    break

            if not is_leaf:
                n2 = n // 2
                node.isLeaf = False
                node.topLeft = helper([row[:n2] for row in g[:n2]])
                node.topRight = helper([row[n2:] for row in g[:n2]])
                node.bottomLeft = helper([row[:n2] for row in g[n2:]])
                node.bottomRight = helper([row[n2:] for row in g[n2:]])
            return node

        return helper(grid)
```