
## 解法一 递归
### 解题思路
递归法，很简单

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        output = list()
        def inorder(node):
            if not node:
                return 
            inorder(node.left)
            output.append(node.val)
            inorder(node.right)
        inorder(root)
        return output
```
## 解法二 遍历
### 解题思路
遍历法，需要通过栈来实现，麻烦一些

### 代码

```python3
class Solution:
    def inorderTraversal(self,root: TreeNode) -> List[int]:
        output = list()
        stack = list()
        tmp = list()
        stack.append(root)
        while stack:
            node = stack[-1]
            if not node:
                stack.pop()
                continue
            if not node.left:
                output.append(node.val)
                stack.pop()
                tmp.append(node)
                if node.right:
                    stack.append(node.right)
            else:
                if node.left not in tmp:
                    stack.append(node.left)
                else:
                    output.append(node.val)
                    tmp.append(node)
                    stack.pop()
                    if node.right:
                        stack.append(node.right)
                    
        return output

            

```