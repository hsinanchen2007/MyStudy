思想：二叉搜索树的中序遍历结果必然是一个递增数列，且不会有重复的节点值

1.递归方法
```
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        nodes =[]
        def search(root):
            if root:
                search(root.left)
                nodes.append(root.val)
                search(root.right)
        search(root)
        return nodes == sorted(set(nodes))
```

2.非递归方法
```
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        stack = []
        p = root
        res = []

        while p or stack :
            while p:
                stack.append(p)
                p = p.left
            
            if stack :
                node = stack.pop()
                res.append(node.val)
                p = node.right
        
        return res == sorted(set(res))
```

其实最早想的是参考数据结构C写的一个方法，根据二叉树的性质判断的递归方法，但是可能由于复杂度比较高，提交不通过
```
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        if (root.left == None and root.right == None):
            return True
        while root.left and root.right :
            if root.val <= root.left.val:
                return False
            elif root.val >= root.right.val:
                return False
            else:
                self.isValidBST(root.left)
                self.isValidBST(root.right)
        
        while root.left:
            if root.val <= root.left.val:
                return False
            else:
                self.isValidBST(root.left)
        
        while root.right:
            if root.val >= root.right.val:
                return False
            else:
                self.isValidBST(root.right)
```
