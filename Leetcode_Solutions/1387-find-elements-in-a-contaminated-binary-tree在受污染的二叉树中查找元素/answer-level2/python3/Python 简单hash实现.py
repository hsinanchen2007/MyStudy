![image.png](https://pic.leetcode-cn.com/24d43f55dbebdaecd4196a8bbcc3cbadc1a25c6ad051518b50cc12b1dc4ef39c-image.png)


```
'''
重构二叉树同时hash保存所有节点数值，查询时候直接查hash表
'''


class FindElements:

    def dfs(self, root: TreeNode, val: int):
        if root is None:
            return

        root.val = val
        self.all_node.add(val)
        self.dfs(root.left, 2*val + 1)
        self.dfs(root.right, 2*val + 2)


    def __init__(self, root: TreeNode):
        self.all_node = set()
        self.dfs(root, 0)


    def find(self, target: int) -> bool:
        return target in self.all_node
```
