![image.png](https://pic.leetcode-cn.com/7d608defc58b83d346d4ab24c44b8753cc0584bba6192f9c30318cef82b0589e-image.png)

```python []
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if root == None:
            return []
        res = []
        nodes = [root]
        while nodes:
            nodes_val = []
            new_nodes = []
            for i in nodes:
                nodes_val.append(i.val)
                if i.left:
                    new_nodes.append(i.left)
                if i.right:
                    new_nodes.append(i.right)
            nodes = new_nodes
            res.append(nodes_val)
        return res
```

