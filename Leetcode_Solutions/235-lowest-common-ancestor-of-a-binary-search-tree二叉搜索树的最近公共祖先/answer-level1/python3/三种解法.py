### 递归--适用于任何二叉树
主要思路是自底向上访问，当某个node节点的左子树,node.val,右子树这3个属性中有两个是包括了p,q的值，就说明是最近公共祖先。
```python
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        self.rst = None
        def lca(node):
            if node==None:
                return 0
            else:
                l_label = lca(node.left)
                r_label = lca(node.right)
                n_label = int(node.val in [p.val,q.val])+l_label+r_label
                self.rst = node
                assert n_label<2
                return n_label
        try:return lca(root)
        except:return self.rst
```
### 迭代--适用于二叉搜索树
主要思路是从根节点开始遍历，当第一次出现节点值在pq之间，就是最近共主。
```python
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        i,j = sorted([p.val,q.val])
        while root:
            if  i<=root.val<=j:
                return root
            elif root.val<i:
                root = root.right
            elif root.val>j:
                root = root.left
        # 执行用时 :80 ms, 在所有 Python3 提交中击败了95.05%的用户
        # 内存消耗 :17.1 MB, 在所有 Python3 提交中击败了100.00%的用户
```
### 递归--适用于二叉搜索树
是上面的递归写法，自底向上，也可以改写为自顶向下
```python
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        i,j = sorted([p.val,q.val])        
        def lca(node):
            if i<=node.val<=j:
                return node
            elif node.val<i:
                return lca(node.right)
            elif node.val>j:
                return lca(node.left)
        return lca(root)
```