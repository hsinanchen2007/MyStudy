最大路径在三种可能里选最大的。
（1）左子树里计算（2）在右子树里计算（2）这棵树的左树深度加右树深度

```
class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int: 
        def depth(root):  #算深度的方法
            if not root:
                return 0
            return max(depth(root.left),depth(root.right))+1
 
       if  not root:
            return 0
        return max(self.diameterOfBinaryTree(root.left),self.diameterOfBinaryTree(root.right),depth(root.right)+depth(root.left))
```


优化了一下，算深度，同时更新最大路径
```
class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        self.res=0
        def travel(root):
            if not root:
                return 0
            left=travel(root.left)
            right=travel(root.right)
            self.res=max(self.res,left+right)
            return max(left,right)+1
        travel(root)
        return self.res
```
