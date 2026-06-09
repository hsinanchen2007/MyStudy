### 解题思路
此处撰写解题思路

### 代码 递归返回的条件是在子树中找到了p或者q，注意，这里是或者。没找到时就返回None。因此，我们可以知道，如果在左子树和右子树都找到了p或者q，那么他们的公共祖先一定是根节点。如果在左子树中没有找到p或者q，那么答案一定在右子树中，反之亦然。

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        if not root or p is root or q is root: # 如果找到了q或者p，则返回root，is == 都行
            return root
        left = self.lowestCommonAncestor(root.left,p,q)
        right = self.lowestCommonAncestor(root.right,p,q)
        if left and right:
            return root
        if not left:
            return right
        if not right:
            return left
        #return None

```