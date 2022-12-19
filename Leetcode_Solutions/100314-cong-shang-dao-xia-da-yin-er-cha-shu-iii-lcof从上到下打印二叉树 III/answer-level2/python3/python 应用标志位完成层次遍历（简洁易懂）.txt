### 解题思路
使用flag标志位，当1，3，5，7等奇数层时flag为True,按正序放入列表
当2，4，6等偶数层时，flag为False,按照反序放入列表


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
        if not root:
            return []
        flag=False
        res=[]
        queue=[root]
        while queue:
            n = len(queue)
            tmp = []
            flag=not flag
            for i in range(n):
                node = queue.pop(0)
                if flag:
                   tmp.append(node.val)
                else:
                    tmp.insert(0,node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
                

            res.append(tmp)
        return res
```