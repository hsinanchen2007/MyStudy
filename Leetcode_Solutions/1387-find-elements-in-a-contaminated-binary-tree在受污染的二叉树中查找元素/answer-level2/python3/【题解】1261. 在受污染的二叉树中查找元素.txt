**方法一：深度优先搜索 + 集合**

在还原二叉树时，我们可以使用深度优先搜索的方法，从根节点开始还原，随后依次递归左右两个孩子节点进行还原。

在还原的过程中，我们可以将所有的值加入集合（HashSet），这样就可以在 $O(1)$ 的时间复杂度判断目标值 `target` 是否在还原后的二叉树中了。

```Python [sol1]
class FindElements:
    def __init__(self, root: TreeNode):
        self.elems = set()

        def dfs(node, val):
            if node:
                node.val = val
                self.elems.add(val)
                dfs(node.left, val * 2 + 1)
                dfs(node.right, val * 2 + 2)

        dfs(root, 0)

    def find(self, target: int) -> bool:
        return target in self.elems
```

**复杂度分析**

- 时间复杂度：还原二叉树的时间复杂度为 $O(N)$，其中 $N$ 是二叉树中的节点数目。判断目标值的时间复杂度为 $O(1)$。

- 空间复杂度：$O(N)$，为集合中所有元素的空间复杂度。