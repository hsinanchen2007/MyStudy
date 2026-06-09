### 解题思路
在102二叉树的层次遍历的基础上，引入一个辅助变量存储当前层的输出，若level为奇数则reverse下

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        #在102的基础上改进
        from collections import deque
        if not root:return []
        queue=deque()
        queue.append(root)
        res=[]
        level=0
        while queue:
            res.append([])
            level_len=len(queue)
            temp=[]
            for i in range(level_len):
                curNode=queue.popleft()
                temp.append(curNode.val)#添加一个辅助变量存储当前层的输出，若level为奇数则reverse下
                #res[level].append(curNode.val)
                if curNode.left:
                    queue.append(curNode.left)
                if curNode.right:
                    queue.append(curNode.right)
            if level%2==1:temp.reverse()
            res[level].extend(temp)
            level+=1        
        return res
```