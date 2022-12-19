### 解题思路
![image.png](https://pic.leetcode-cn.com/1b84c0fa4dd90f96d2a015f54c752afc60602de82d65def4f6a2e9e8d43cf406-image.png)

-   如果目标节点小于当前节点，当前节点有可能是目标节点的后继节点，放入栈中保存
-   如果目标节点大于当前节点，继续判断右节点
-   如果当前节点等于目标节点，那么如果有右节点，就返回右节点的最左节点，如果没有，就返回栈中最后一个元素


### 代码

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderSuccessor(self, root: 'TreeNode', p: 'TreeNode') -> 'TreeNode':
        cur = root
        stack = []
        while cur:
            if cur.val > p.val:
                stack.append(cur)
                cur = cur.left
            elif cur.val < p.val:
                cur = cur.right
            else:
                if cur.right:
                    temp = cur.right
                    while temp.left:
                        temp = temp.left
                    return temp
                else:
                    if stack:
                        return stack[-1]
                    else:
                        return None

        return None
```