### 解题思路
此处撰写解题思路

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        queue1=[root]
        queue2=[]
        result_list=[]
        if not root:
            return root
        while queue1 or queue2:#有一个不为空
            list=[]
            if queue1:
                for node in queue1:
                    if node:
                        list.append(node.val)
                        if node.left:
                           queue2.append(node.left)
                        if node.right:
                           queue2.append(node.right)
                queue1=[]
            else:
                for node in queue2:
                    if node:
                        list.append(node.val)
                        if node.left:
                           queue1.append(node.left)
                        if node.right:
                           queue1.append(node.right)            
                queue2=[]
            result_list.insert(0,list)    
        return result_list

                        


```