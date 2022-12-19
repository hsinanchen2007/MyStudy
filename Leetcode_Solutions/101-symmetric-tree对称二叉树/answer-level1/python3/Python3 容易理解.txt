### 解题思路
这道题需要用到两个函数，一个是答案返回值函数isSymmetric， 另一个是sub用来递归调用， sub函数接受两个树作为比较， 分别对应 **左边的子树和右边的子树** 或者 **右边的子树和左边的子树**， 开始时，调用两次自己（根树）

如果 树1 为 None 而且 树2 为 None：
    那么 返回相同
否则 如果 树1为 None 但是 树2 不为 None：
    那么 返回不相同
否则如果 树1 的值 等于 树2 的值：
    那么 递归寻找子树
否则 
    树1 的值 不等于 树2 的值

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sub(self, r1: TreeNode, r2: TreeNode) -> bool:
        if r1 == None and r2 == None:
            return True
        elif r1 == None or r2 == None:
            return False
        elif r1.val == r2.val:
            return self.sub(r1.right, r2.left) and self.sub(r1.left, r2.right)
        else:
            return False

    def isSymmetric(self, root: TreeNode) -> bool:
        return self.sub(root, root)
        
```