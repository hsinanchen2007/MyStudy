### 解题思路
与102题一样，再reverse下就好

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
        #<102.二叉树的层次遍历>得到结果再reverse下
        from collections import deque
        def levelOrder(root):
            if not root:return []
            queue=deque()
            #visited=set()
            queue.append(root)
            res=[]
            level=0
            while queue:
                res.append([])
                level_len=len(queue)
                for i in range(level_len):
                    curNode=queue.popleft()
                    res[level].append(curNode.val)
                    if curNode.left:
                        queue.append(curNode.left)
                    if curNode.right:
                        queue.append(curNode.right)
                level+=1
            return res
        res= levelOrder(root)
        res.reverse()
        return res  

```