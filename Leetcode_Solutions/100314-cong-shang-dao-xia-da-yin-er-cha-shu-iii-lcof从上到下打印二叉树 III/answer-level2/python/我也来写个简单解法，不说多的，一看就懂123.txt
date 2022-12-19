### 解题思路
直接模拟就好。
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
        if not root:  return []
        res=[]
        cur=[root]
        d=1   #记录到那一层了，奇数层从左到有，偶数层从右到左
        from collections import deque
        while cur:
            tmp=deque()  #零时记录当前层的值
            nxt=[]       #下一层的节点有哪些
            for i in cur:
                if d%2:
                    tmp.append(i.val)
                else:
                    tmp.appendleft(i.val)
                if i.left:
                    nxt.append(i.left)
                if i.right:
                    nxt.append(i.right)
            res.append(list(tmp))
            cur=nxt
            d+=1
        return res
            

```