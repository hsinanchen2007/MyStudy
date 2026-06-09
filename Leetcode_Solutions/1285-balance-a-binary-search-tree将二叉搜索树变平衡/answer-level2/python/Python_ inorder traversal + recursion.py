### 解题思路
先用中序遍历得到一个有序数组，然后把数组装换成平衡二叉搜索树。具体方法是找到中间数作为root，左边为左子树，右边为右子树，以此做递归。
### 代码

```python
class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
        return self.build(self.inorder(root))
              
    def inorder(self, root):
        if not root:
            return []
        return self.inorder(root.left) + [root.val] + self.inorder(root.right)
    
    def build(self, lst):
        if not lst: return None
        mid = len(lst)//2
        root = TreeNode(lst[mid])
        root.left = self.build(lst[:mid])
        root.right = self.build(lst[mid+1:])
        return root
```