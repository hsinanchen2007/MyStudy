都在代码里了
```python
class Solution:
    def removeLeafNodes(self, root: TreeNode, target: int) -> TreeNode:
        def dfs(node):  #返回一个布尔值，表示这个节点是否需要删除
            if not node:
                return False #这里返回什么无所谓，反正都是None
            if not node.left and not node.right and node.val==target: #判断是否符合删除的条件
                return True
            if dfs(node.left):
                node.left=None
            if dfs(node.right):
                node.right=None
            return not node.left and not node.right and node.val==target #删除之后需要重新判断
        if root and dfs(root):
            root=None #根节点如果符合条件同样需要删除
        return root
```