### 解题思路
路径总和II
基本思路和路径综合I一样
调用函数找路径就几行
把所有路径找出来，然后把叶节点，和sum==0的找出来加入li中
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
 
   
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        li=[]
        if  root is None:
            return li
        def find(root,sum,path):
            sum-=root.val
            if root.left is None and root.right is None and sum==0:
                li.append(path+[root.val])
            if root.left:
                find(root.left,sum,path+[root.val])
            if root.right:
                find(root.right,sum,path+[root.val])
        find(root,sum,[])
        return li
```