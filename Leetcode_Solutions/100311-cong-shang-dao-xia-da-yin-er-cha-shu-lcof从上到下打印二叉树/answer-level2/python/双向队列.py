使用双向队列，把根节点压入，从队列左边取出节点后把节点的左右节点压入队列尾部，直到双向队列为空，代码如下
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
import collections

class Solution:
    def levelOrder(self, root: TreeNode) -> List[int]:
        temp=collections.deque()
        ans=[]
        if root:
            temp.append(root)
            while temp:
                cur=temp.popleft()
                ans.append(cur.val)
                if cur.left:
                    temp.append(cur.left)
                if cur.right:
                    temp.append(cur.right)
        return ans
```

