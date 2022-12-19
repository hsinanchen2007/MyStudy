### 解题思路
此处撰写解题思路
添加翻转flag
### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []
        flag = 1
        queue =[root]
        resp = []
        while queue:
            tmp = []
            for i in range(len(queue)):
                t = queue.pop(0)
                if t.left:
                    queue.append(t.left)
                if t.right:
                    queue.append(t.right)
 
                tmp.append(t.val)
            if flag == 1:
                flag = 2
            else:
                tmp.reverse()
                flag =1
            resp.append(tmp)
        return resp
```