### 解题思路
此处撰写解题思路
1. 构建一个队列，然后把树放进去
2. 利用队列的特性，一层一层读取树的元素，每读取一层，层数加1
3. 直到所有层遍历完毕，输出层数
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
        if root == None:
            return 0
        stack = [root]
        i = 0
        while len(stack) != 0:
            n = len(stack)
            i += 1
            # print(stack)
            for k in range(n):
                temp = stack.pop(0)
                if temp.left:
                    stack.append(temp.left)
                if temp.right:
                    stack.append(temp.right)
        return i 
```