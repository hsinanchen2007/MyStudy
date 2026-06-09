### 解题思路
每一层分别层序遍历

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
        a=[]#存结点 
        c=[]#存放分层后的每一层遍历的值合集
        if root==None:
            return []
        a.append(root)
        while a:
            b=[]#用于存放每一层遍历后的值，每一层遍历完后重置
            for i in range(len(a)):#每一层的结点数
                count=a.pop(0)
                b.append(count.val)
                if count.left!=None:
                    a.append(count.left)
                if count.right!=None:
                    a.append(count.right)
            c.append(b)#每一层的值分别存入c中
        return c[::-1] #逆置
```