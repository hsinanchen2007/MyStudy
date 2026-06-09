### 解题思路
写一个函数conutS判断左子树有多少结点：分为1、左子树是空 2、左子树是根节点 3、左子树有左节点 4、左子树有右节点 5、左子树左右节点都有
从而得到根节点的所在位置，进而递归继续在左子树或右子树中寻找。
当找到根节点满足k，输出。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        if not root:
            return 

        def conutS(root,count): 
            if not root:
                return 0         
            if not root.left and not root.right:
                return 1
            if not root.left and root.right:
                count=1+conutS(root.right,count)
            if root.left and not root.right:
                count=1+conutS(root.left,count)
            else:
                count=1+conutS(root.left,count)+conutS(root.right,count)
            return count

        count=conutS(root.left,0)
        print(count)
        if count>k-1:
            return self.kthSmallest(root.left,k)
        elif count==k-1:
            return root.val
        else:
            return self.kthSmallest(root.right,k-count-1)
```