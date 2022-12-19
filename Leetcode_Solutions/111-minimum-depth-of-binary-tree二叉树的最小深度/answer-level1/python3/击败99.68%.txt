![9134248a6ca3ad2bb60128560317e13.png](https://pic.leetcode-cn.com/d8f9024deec7b800186aa9ef26e714a18f4d0c2f6b8bc55915ab723ffeeb438a-9134248a6ca3ad2bb60128560317e13.png)

```python []
class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if root == None:
            return 0
        nodes = [root]
        res = 1
        while nodes:
            new_nodes = []
            for i in nodes:
                if i.left == None and i.right == None:
                    return res
                if i.left:
                    new_nodes.append(i.left)
                if i.right:
                    new_nodes.append(i.right)
            res += 1
            nodes = new_nodes
        return res
```


