## 1. 相关知识点
**二叉搜索树(Binary Search Tree)**,其性质：
- 小于父节点的键都在左子树中；
- 大于父节点的键则都在右子树中；
- 左右子树也分别为二叉搜索树。

## 2. 解题思路
- 非递归：利用二叉搜索树的性质。
    1. root == None，return None
    2. p == q, return  p
    3. p < root, q < root, 则root.left
    4. p > root, q > root, 则root.right
    5. p 和 q 在 root 的左右两边时，return root

- 递归：左子树的值小于等于根节点，右子树的值大于等于根节点，分情况递归即可

## 3. 代码
**- 非递归**
```
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if root == None:
            return root
        while True:
            if p.val < root.val and q.val < root.val:
                root = root.left
            elif p.val > root.val and q.val > root.val:
                root = root.right
            else:
                return root
                break
```
**- 递归**
时间复杂度 O(logN)
```
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if root == None:
            return root
        if p.val < root.val and q.val < root.val:
            return self.lowestCommonAncestor(root.left,p,q)
        elif p.val > root.val and q.val > root.val:
            return self.lowestCommonAncestor(root.right,p,q)
        else:
            return root
```
