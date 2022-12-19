### 解题思路
N叉树的后序遍历，同二叉树的后序遍历

### 代码

```python
"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""#都是套路，记住套路
class Solution(object):
    def postorder(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """
        ans=[]
        if not root:
            return root
        def postTraversal(node):
            if not node:
                return 
            for cur in node.children:#先遍历孩子节点
                postTraversal(cur)
            ans.append(node.val)#再将当前节点的值写入ans[]中
        postTraversal(root)
        return ans
```