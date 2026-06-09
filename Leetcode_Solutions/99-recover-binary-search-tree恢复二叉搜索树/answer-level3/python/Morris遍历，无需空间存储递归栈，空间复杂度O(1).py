### 解题思路
详见注释

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def recoverTree(self, root):
        """
        :type root: TreeNode
        :rtype: None Do not return anything, modify root in-place instead.
        """
        # Morris遍历，无需空间存储递归栈，空间O(1)

        predecessor = pre = x = y = None
        while root:
            # 如果存在左子树
            if root.left:
                predecessor = root.left
                # 寻找左子树的最右节点，作为根节点的前驱
                while predecessor.right and predecessor.right != root:
                    predecessor = predecessor.right
                # 如果前驱的右节点是空，设置右节点为根
                if not predecessor.right:
                    predecessor.right = root
                    # 访问左子树
                    root = root.left
                # 如果不是空，就是根
                else:
                    # 访问该节点，断开链接，然后访问右子树
                    if pre and pre.val >= root.val:
                        # 第一次出现逆序对，设置x为第一个逆序节点
                        if not x:
                            x = pre
                        # 每次出现逆序对，都要把y设置为最后一个逆序节点
                        y = root
                    pre = root
                    predecessor.right = None
                    root = root.right
            # 如果没有左子树，直接访问右子树
            else:
                if pre and pre.val >= root.val:
                    if not x:
                        x = pre
                    y = root
                pre = root
                root = root.right

        x.val, y.val = y.val, x.val


```