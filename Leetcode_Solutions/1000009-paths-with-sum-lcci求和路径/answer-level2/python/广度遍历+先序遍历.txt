### 解题思路
此处撰写解题思路
广度遍历一层一层每个节点依次深度遍历
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.count=0
    def pathSum(self, root: TreeNode, sum: int) -> int:

        def helper(node,n):
            if not node:
                return
            if n==node.val:
                self.count+=1
            if node.left is not None:
                helper(node.left,n-node.val)
            if node.right is not None:
                helper(node.right,n-node.val)
            return self.count

        if not root:
            return 0
        queue=[root]
        while queue:
            n=len(queue)
            m=sum
            while n>0:
                cur_node=queue.pop(0)
                helper(cur_node,m)
                if cur_node.left is not None:
                    queue.append(cur_node.left)
                if cur_node.right is not None:
                    queue.append(cur_node.right)
                n-=1
        return self.count
                


            


```