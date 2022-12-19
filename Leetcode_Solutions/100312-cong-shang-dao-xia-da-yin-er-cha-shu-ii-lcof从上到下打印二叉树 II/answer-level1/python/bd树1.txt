### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if root == None:
            return []
        queue = [root]
        level = [[root.val]]
        tmp = []
        while queue: 
            for _ in range(len(queue)):           
                node = queue.pop(0)
                if node.left:
                    queue.append(node.left)
                    tmp.append(node.left.val)
                if node.right:
                    queue.append(node.right)
                    tmp.append(node.right.val)     
            if tmp:
                level.append(tmp)
            tmp = []
        return level
            

```