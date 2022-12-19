### 解题思路
利用辅助栈达到层次遍历的目的，右孩子先入栈左孩子后入栈，则左孩子先出栈右孩子后出栈
分层输出，借助Map，同一层的节点拥有相同的key

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return []
        if root.left is None and root.right is None:
            return [[root.val]]
        
        levelMap = {}
        stack = [(1, root)]
        while stack:
            cur_level, root = stack.pop()
            if root:
                if cur_level in levelMap:
                    cur_value = levelMap[cur_level]
                    cur_value.append(root.val)
                    levelMap[cur_level] = cur_value
                else:
                    levelMap[cur_level] = [root.val]
                stack.append((cur_level + 1, root.right))
                stack.append((cur_level + 1, root.left))
        
        res = []
        for level in sorted(levelMap.keys(), reverse=True):
            res.append(levelMap[level])
        
        return res


            

```