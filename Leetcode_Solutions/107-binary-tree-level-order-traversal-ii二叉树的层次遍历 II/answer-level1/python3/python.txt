### 解题思路
层序遍历

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
        if not root:
            return []
        res=[]
        deque=collections.deque()
        deque.append(root)
        while deque:
            count=len(deque)
            temp=[]
            for i in range(count):
                node=deque.popleft()
                temp.append(node.val)
                if node.left:
                    deque.append(node.left)
                if node.right:
                    deque.append(node.right)
            res.append(temp)
        return res[::-1]


    
```