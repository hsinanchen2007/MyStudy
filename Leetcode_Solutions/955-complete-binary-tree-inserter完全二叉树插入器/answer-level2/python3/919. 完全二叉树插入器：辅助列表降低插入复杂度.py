![image.png](https://pic.leetcode-cn.com/7e4374882e9bd686ef46e800729361bd67d26814cbebe7ac87450e7efe4c1974-image.png)

$O(n)$预处理了个按层次遍历的二叉树的记录列表，插入的时候坐标折半$O(1)$就可以直接找到父节点了。

```python []
class CBTInserter:

    def __init__(self, root: TreeNode):
        d = collections.defaultdict(list)
        def pre(root, i):
            if root:
                d[i].append(root)
                pre(root.left, i + 1)
                pre(root.right, i + 1)
        pre(root, 0)
        self.p = []
        for arr in d.values():
            self.p += arr
        self.root = root

    def insert(self, v: int) -> int:
        index = len(self.p) - 1
        self.p.append(TreeNode(v))
        if index & 1 == 0:
            self.p[index >> 1].left = self.p[-1]
        else:
            self.p[index >> 1].right = self.p[-1]
        return self.p[index >> 1].val

    def get_root(self) -> TreeNode:
        return self.root
```
