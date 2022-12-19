
![image.png](https://pic.leetcode-cn.com/2e1763ddcfdc3581896122372a6890c11dc9385312ded9068712d32616a3fa19-image.png)

```python []
class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        d = root and [root]
        while d:
            yield [r.val for r in d]
            d = [t for r in d for t in r.children]
```