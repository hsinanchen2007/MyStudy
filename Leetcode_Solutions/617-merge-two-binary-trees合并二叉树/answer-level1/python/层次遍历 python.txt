### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def mergeTrees(self, t1: TreeNode, t2: TreeNode) -> TreeNode:
        """
        层次遍历，把结果归在t1上
        """
        if not t1:
            return t2
        if not t2:
            return t1
        t1.val+=t2.val
        queue = [(t1,t2)]
        while queue:
            queue_next = []
            # 寻找下一层孩子节点对
            for node1, node2 in queue:
                if not node2.left and not node2.right:
                    continue
                if node2.left:
                    if node1.left:
                        node1.left.val+=node2.left.val
                        queue_next.append((node1.left, node2.left))
                    else:
                        node1.left = node2.left
                if node2.right:
                    if node1.right:
                        node1.right.val+=node2.right.val
                        queue_next.append((node1.right, node2.right))
                    else:
                        node1.right = node2.right
            queue = queue_next
        return t1
```