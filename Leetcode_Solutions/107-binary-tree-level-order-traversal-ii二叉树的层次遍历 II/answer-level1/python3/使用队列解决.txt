### 解题思路
此处撰写解题思路
1. 一个队列用于保存树结构，另一个保存遍历的结果；
2. 利用队列的特性，层序遍历每层的结果；
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
        if root == None:
            return []
        stack = [root]
        result = []
        while len(stack) != 0:
            num = len(stack)
            r_temp = []
            for i in range(num):
                node = stack.pop(0)
                r_temp.append(node.val)
                if node.left:
                    stack.append(node.left)
                if node.right:
                    stack.append(node.right)
            result.insert(0, r_temp)
        return result
```