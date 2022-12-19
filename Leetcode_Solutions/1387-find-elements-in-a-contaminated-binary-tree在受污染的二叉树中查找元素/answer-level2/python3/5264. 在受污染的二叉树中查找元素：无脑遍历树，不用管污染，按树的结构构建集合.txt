![image.png](https://pic.leetcode-cn.com/4410146952d8ea32fe11e3284e051e2c25bc4a1741d2411c082a8856acd77c27-image.png)

无脑遍历树，不需要获取节点的值，也不用管节点的值是否被污染，直接按公式把值存进集合，输出时判断是否存在于集合就可以了，92ms仅供参考。

```python []
class FindElements:

    def __init__(self, root: TreeNode):
        self.d = set()
        def f(r, x):
            if r:
                self.d.add(x)
                f(r.left, 2 * x + 1)
                f(r.right, 2 * x + 2)
        f(root, 0)

    def find(self, target: int) -> bool:
        return target in self.d
```
