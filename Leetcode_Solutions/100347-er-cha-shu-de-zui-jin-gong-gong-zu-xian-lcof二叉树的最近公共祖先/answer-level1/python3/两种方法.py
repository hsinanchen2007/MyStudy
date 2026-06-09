# 后序遍历法
实际上是检测子树是否同时包含两个结点，如果一个根节点不为两结点任意个，则两结点必定包含于左或右子树中
若某子树包含一个或以上结点，则返回值不为空，若为空，说明两结点在另一个子树里
若两子树返回值均不为空，则在根节点下

```python []
class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        if not root or root == p or root == q:
            return root
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)
        if not left:
            return right
        if not right:
            return left
        return root
```


 

# 查找路径法
通过查找通往两结点的路径，找到最后一个公共节点
```python []
class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        stack1,stack2=[],[]
        def dfs(root,stack,node):
            if not root:
                return False
            stack.append(root)
            if root==node:
                return True
            elif dfs(root.left,stack,node) or dfs(root.right,stack,node):
                return True
            stack.pop()
        dfs(root,stack1,p)
        dfs(root,stack2,q)
        i=0
        while i<len(stack1) and i<len(stack2) and stack1[i]==stack2[i]:
            i+=1
        return stack1[i-1]
```
