### 解题思路
对二叉搜索树理解不深，一开始果然走入误区，忘记验证 左子树中有比上一节点大的值，或右子树中有比上一节点小的值 的情况，查看题解后，发现大家把上一节点值传入递归，觉得不爽，还是老老实实用中序遍历后递增序列的特性来判断。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        
        preNodeVal = -float("inf")
        stack = [(root, False)]
        while stack:
            node, flag = stack.pop()
            if node:
                if flag:
                    if node.val > preNodeVal:
                        preNodeVal = node.val
                    else:
                        return False
                else:
                    stack.append((node.right, False))
                    stack.append((node, True))
                    stack.append((node.left, False))
        return True



        # if not root: return True
        # leftValid, rightValid = True, True

        # if root.left:
        #     if root.left.val < root.val:
        #         leftValid =  self.isValidBST(root.left)
        #     else:
        #         leftValid = False
        
        # if root.right:
        #     if root.right.val > root.val:
        #         rightValid = self.isValidBST(root.right)
        #     else:
        #         rightValid = False

        # return leftValid and rightValid

```