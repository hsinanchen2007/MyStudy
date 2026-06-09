### 解题思路
利用堆栈逆序遍历二叉搜索树，每个节点都等于本身和后续节点之和。

### 代码

```python3

class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        
        tmpsum = 0
        stack = [(root, False)]
        while stack:
            node, flag = stack.pop()
            if node:
                if flag:
                    node.val +=  tmpsum
                    tmpsum = node.val 
                else: 
                    if node.left: stack.append((node.left, False))
                    stack.append((node, True))
                    if node.right: stack.append((node.right, False))

        return root
```