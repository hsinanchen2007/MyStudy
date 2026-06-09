### 解题思路
思路：遍历每个节点，检查以该节点为根的树是否和t相同
要点：
1、编写判断函数，输入是两个根节点，输出是树是否相同
2、编写遍历流程

1、使用递归的方式，依次判断根节点是否相同，左子树是否相同，右子树是否相同
2、使用层序遍历，遍历每个节点

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:
        def if_the_same(root1,root2):
            if not root1 and not root2:
                return True
            if not root1 or not root2:
                return False
            if not root1.left and not root1.right and not root2.left and not root2.right:
                return root1.val==root2.val
            if root1.val!=root2.val:
                return False
            if not if_the_same(root1.left,root2.left):
                return False
            return if_the_same(root1.right,root2.right)
        stack=[s]
        while len(stack)>0:
            current=stack.pop(0)
            if if_the_same(current,t):
                return True
            if current.left:
                stack.append(current.left)
            if current.right:
                stack.append(current.right)
        return False

            


            

```