### 解题思路
使用栈实现二叉树的先序遍历
将以各个节点为终点对应的前n项和(起点为从根节点至当前节点)作为列表保存，在遍历过程中需要不断更新

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        if not root:
            return 0
        res=0
        stack=[]
        stack.append((root,[root.val]))
        while stack:
            node,value=stack.pop()
            res+=value.count(sum)
            value.append(0)
            if node.right:
                stack.append((node.right,[i+node.right.val for i in value]))
            if node.left:
                stack.append((node.left,[i+node.left.val for i in value]))
        return res

```