### 解题思路
二叉搜索树有什么性质？
左子树所有的值<根节点<右子树所有的值

那对于根节点，哪几个节点和它的差最小？如图对于根节点5，哪些节点和他差最小(最接近)？
![image.png](https://pic.leetcode-cn.com/69f943afb6879d88c477b8815b8ab66b7115d31bfa33bb1cc5e4610bac817cd7-image.png)
我们可以看到2<5,而3>2，因而在左子树中3最接近5，同理在右子树中6最接近5。
不失一般的，对于根节点来说，和他最接近的节点是左子树的最右节点，因为左子树都小于根节点，而左子树的最右节点又是左子树中最大的，因此它最接近根节点。同理也有右子树的最左节点
遍历树，将每个节点和与他最接近的两个节点做差，维护一个最小差变量，就能解决这道题。

![image.png](https://pic.leetcode-cn.com/1d1ae21d709dabd787a76163828cee4fb1abedb01cc4304061a73f158dca3c56-image.png)

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def getMinimumDifference(self, root: TreeNode) -> int: 
        self.min_diff=999
        def get_left(root):
            if not root:
                return
            if not root.left:
                return root.val
            return get_left(root.left)

        def get_right(root):
            if not root:
                return
            if not root.right:
                return root.val
            return get_right(root.right)

        def get(root):
            if not root:
                return
            if not root.left and not root.right:
                return
            left_val=get_right(root.left)
            right_val=get_left(root.right)
            if left_val and root.val-left_val<self.min_diff:
                self.min_diff=root.val-left_val
            if right_val and right_val-root.val<self.min_diff:
                self.min_diff=right_val-root.val
            get(root.left)
            get(root.right)
        get(root)
        return self.min_diff


```