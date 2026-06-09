![image.png](https://pic.leetcode-cn.com/8c92a803e5e82c9650852b53f3a31a6dbec50fa4d68ff964b0e326df298304ef-image.png)

和其他大佬的程序大差不差，就是用python写的而已。
如果根结点值大于目标值，就往左边递归准备插进左子树，根结点小于目标值就准备插入右子树。
直到递归到某个子树，当根结点的值大于目标值val，且左子树为空，这时候再递归进入左子树就会触发插入目标值的叶子的操作；
当值若是小于val且右子树恰好为空时，则会插入在右边。
```
class Solution:
    def insertIntoBST(self, root: TreeNode, val: int) -> TreeNode:
        if not root:
            return TreeNode(val)
        if root.val>val:
            root.left=self.insertIntoBST(root.left,val)
        if root.val<val:
            root.right=self.insertIntoBST(root.right,val)
        return root
```
