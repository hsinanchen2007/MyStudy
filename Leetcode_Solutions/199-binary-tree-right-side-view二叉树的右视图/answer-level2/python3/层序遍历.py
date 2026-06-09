### 解题思路
按照层序遍历的思路写就行了，每次添加一个队尾的值

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        from collections import deque
        if not root:
            return []
        q=deque()
        q.append(root)
        res=[]
        while q:
            cnt=len(q)
            res.append(q[-1].val)
            for i in range(cnt):
                tmp=q.popleft()
                if tmp.left:
                    q.append(tmp.left)
                if tmp.right:
                    q.append(tmp.right)
            # tmp=q.popleft()
            # res.append(tmp.val)
            # if tmp.left:
            #         q.append(tmp.left)
            # if tmp.right:
            #     q.append(tmp.right)
          
        return res
        
```