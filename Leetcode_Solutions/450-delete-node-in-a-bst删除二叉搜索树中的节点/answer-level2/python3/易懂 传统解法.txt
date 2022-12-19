### 解题思路

搜索节点的流程
key与当前节点的值进行比较，如果大于当前节点的值，就与此节点的右孩子进行比较；如果小于当前节点的值，就与此节点的左孩子进行比较；如果等于当前节点的值，则进行替换操作。

替换操作最好考虑所有情况：
当前节点是其父节点的左孩子还是右孩子？
当前节点有无左右孩子？

最后分类讨论、替换删除即可

### 代码

```python3
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        cursor, p_node, direction = root, root, None
        while cursor is not None:
            if cursor.val > key:
                p_node, cursor, direction = cursor, cursor.left, 1
            elif cursor.val < key:
                p_node, cursor, direction = cursor, cursor.right, 0
            else:
                if direction == 1:
                    # 待删除节点的左右孩子均为None
                    if cursor.left is None and cursor.right is None:
                        p_node.left = None
                    # 待删除节点的左孩子为None，右孩子不为None
                    elif cursor.left is None and cursor.right is not None:
                        p_node.left, cursor.right = cursor.right, None
                    # 待删除节点的右孩子为None，左孩子不为None
                    elif cursor.right is None and cursor.left is not None:
                        p_node.left, cursor.left = cursor.left, None
                    # 待删除节点的左右孩子均不为为None
                    elif cursor.right is not None and cursor.left is not None:
                        _cursor = cursor.left
                        while _cursor.right is not None:
                            _cursor = _cursor.right
                        _cursor.right, cursor.right = cursor.right, None
                        # cursor.right = None
                        p_node.left, cursor.left = cursor.left, None
                        # cursor.left = None
                elif direction == 0:
                    # 待删除节点的左右孩子均为None
                    if cursor.left is None and cursor.right is None:
                        p_node.right = None
                    # 待删除节点的左孩子为None，右孩子不为None
                    elif cursor.left is None and cursor.right is not None:
                        p_node.right, cursor.right = cursor.right, None
                    # 待删除节点的右孩子为None，左孩子不为None
                    elif cursor.right is None and cursor.left is not None:
                        p_node.right, cursor.left = cursor.left, None
                    # 待删除节点的左右孩子均不为为None
                    elif cursor.right is not None and cursor.left is not None:
                        _cursor = cursor.left
                        while _cursor.right is not None:
                            _cursor = _cursor.right
                        _cursor.right, cursor.right = cursor.right, None
                        p_node.right, cursor.left = cursor.left, None
                elif direction is None:
                    # 待删除节点的左右孩子均为None
                    if cursor.left is None and cursor.right is None:
                        return None
                    # 待删除节点的左孩子为None，右孩子不为None
                    elif cursor.left is None and cursor.right is not None:
                        root, cursor.right = cursor.right, None
                    # 待删除节点的右孩子为None，左孩子不为None
                    elif cursor.right is None and cursor.left is not None:
                        root, cursor.left = cursor.left, None
                    # 待删除节点的左右孩子均不为为None
                    elif cursor.right is not None and cursor.left is not None:
                        _cursor = cursor.left
                        while _cursor.right is not None:
                            _cursor = _cursor.right
                        _cursor.right, cursor.right = cursor.right, None
                        root, cursor.left = cursor.left, None
                break
        return root
        
```