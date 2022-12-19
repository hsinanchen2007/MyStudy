### 解题思路
- 根据深度优先遍历的先序遍历来遍历二叉树
- 当到达叶子节点，路径和等于目标和，那么就返回True,结束搜索。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        
        path = [] #保存路径
        return self.func(path,root,sum)  
       
        
    def func(self,path,root,sums): #sum要改个名称，不然会和sum()函数冲突
        if root is None:
            return 
        path.append(root.val)
        print(path)
        if (root.left is None) and (root.right is None) and (sum(path[:])== sums):
            return True 
        s1 = self.func(path,root.left,sums)
        s2 = self.func(path,root.right,sums)
        path.pop()
        if s1 or s2:
            return True
        


```