![image.png](https://pic.leetcode-cn.com/81cd1720dde91f78ba7eeeaaac2c7e6444e680437d87e555d37a25bf30d703e4-image.png)

前序遍历树，字典的每个`key`是层数，`value`是每层值的列表，输出时利用了字典遍历序等于定义序的特点。

68ms，92%，时间复杂度$O(N)$，空间复杂度$O(H)$。

```python []
class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        d = collections.defaultdict(list)
        def f(r, i):
            if r:
                d[i] += [r.val]
                f(r.left,i + 1)
                f(r.right,i + 1)
        f(root, 0)
        return [sum(vals) / len(vals) for vals in d.values()]
```
