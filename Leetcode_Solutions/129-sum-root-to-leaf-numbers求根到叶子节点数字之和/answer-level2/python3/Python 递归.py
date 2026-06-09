### 解题思路
先递归得到所有路径
之后将路径转为数字并求和

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        path=[]
        def get_path(root,temp_path):
            if not root:
                return
            if not root.left and not root.right:
                temp_path.append(root.val)
                path.append(temp_path)
                return
            temp_path.append(root.val)
            se_temp_path=temp_path.copy()
            get_path(root.left,se_temp_path)
            get_path(root.right,temp_path)
        get_path(root,[])
        print(path)
        res=0
        for i in path:
            temp_str=''
            for j in i:
                temp_str+=str(j)
            print(temp_str)
            res+=int(temp_str)
        return res
        
            
```