### 解题思路
#增加与之相同的二叉树，判断是否为镜像
#1、两个树的节点值相等
#2、一颗树的该节点的左子节点，与另一颗树同样位置的节点的右子节点相等
#3、一颗树的该节点的右子节点，与另一颗树同样位置的节点的左子节点相等
#4、若以上都成立，则该二叉树为镜像结构

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root == None:
            return True
        
        stacks = [root.left, root.right]
        flag = True
        while len(stacks)>0:
            left = stacks.pop(0)
            right = stacks.pop(0)

            if not left and not right:
                continue
            
            if not left or not right:
                flag = False
                break
            
            if left.val != right.val:
                flag = False
                break

            stacks.extend([left.left,right.right,left.right,right.left])
        
        return flag
```