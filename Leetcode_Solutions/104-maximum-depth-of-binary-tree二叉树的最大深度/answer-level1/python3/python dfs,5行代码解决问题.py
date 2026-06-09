### 解题思路
此处撰写解题思路
深度搜索，先搜完左边，再搜右边，python写代码真的是便利，越来越喜欢python，嵌套函数真香，这个语法很有韵味。记录学习算法的第一周
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        def isMax(node:TreeNode,len1):
            if node != None:
                return max(isMax(node.left,len1+1),isMax(node.right,len1+1)) 
            return len1
        return isMax(root,0)
```


