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
        count = 1
        while queue: 
            count = count + 1
            for _ in range(len(queue)):                           
                node = queue.pop(0)
                if node.left:
                    queue.append(node.left)
                    tmp.append(node.left.val)
                if node.right:
                    queue.append(node.right)
                    tmp.append(node.right.val)     
            if tmp and count % 2 == 0:
                level.append(tmp[::-1])
            if tmp and count % 2 == 1:
                level.append(tmp)
            tmp = []
        return level
```