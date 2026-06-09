### 解题思路
大概就是这个模版，画个二叉树一步一步跟着走
记住栈里的情况，看什么时候需要把pop出的数据放进res
看了解答区大佬的前序，自己实现下中序后续，还是很有收获

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def inorderTraversal(self, root):
        res=[]
        stack=[]
        cur=root
        while stack or cur:
            while cur:
                stack.append(cur)
                cur=cur.left
            top=stack.pop()
            res.append(top.val)
            cur=top.right
        return res

    
```