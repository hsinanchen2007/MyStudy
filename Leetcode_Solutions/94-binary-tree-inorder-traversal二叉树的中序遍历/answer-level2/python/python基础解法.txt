### 解题思路
1. 递归，递归的终止条件为root为空，中序遍历的条件为左中右，所以先将root.left都打印出来，然后加上root.val,在加上root.right
2. 使用迭代来实现中序遍历，主要是靠栈来实现，每次给curr赋予curr.left，当curr不存在的时候，从栈里面推出最新的节点，将值记录，然后将root.right赋值给curr

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
        # if not root:
        #     return []
        # return self.inorderTraversal(root.left) + [root.val] + self.inorderTraversal(root.right)
        stack = []
        result = []
        curr = root
        while stack or curr:
            if curr:
                stack.append(curr)
                curr = curr.left
            else:
                curr = stack.pop()
                result.append(curr.val)
                curr = curr.right
        return result
```