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
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root :
            return []
        levels = []
        depth = 1
        queque = [root, ]
        while queque:
            lens = len(queque)
            x=[]
            for i in range(lens):
                p = queque.pop(0)#切记要先取出
                x.append(p.val)
                if p.left:
                    queque.append(p.left)
                if p.right:
                    queque.append(p.right)
            if not depth%2:
                x.reverse()
                levels.append(x)
            else:
                levels.append(x)
            depth+=1
        
        return levels

            
       
```