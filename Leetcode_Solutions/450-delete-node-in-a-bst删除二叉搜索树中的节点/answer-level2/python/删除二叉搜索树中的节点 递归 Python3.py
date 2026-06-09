### 解题思路
生无可恋。。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # 找到这个值
    def find_left_max_node_val(self, node):
        node = node.left
        while node.right:
            node = node.right
        return node.val
    
    def find_right_min_node_val(self, node):
        node = node.right
        while node.left:
            node = node.left
        return node.val

    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        if not root:
            return None

        if key < root.val:
            root.left = self.deleteNode(root.left, key)
        elif key > root.val:
            root.right = self.deleteNode(root.right, key)
        else:
            # 两侧都没有的时候是叶子节点 直接删掉
            # 否则 用 右子树的最小值 或 左子树的最大值 替换目标节点值 再删掉
            if not root.left and not root.right:  # 两个都没有
                root = None
            elif root.right:  # 有右侧 或 两侧都有
                root.val = self.find_right_min_node_val(root)
                root.right = self.deleteNode(root.right, root.val)
            else:  # 有左侧 或 两侧都有
                root.val = self.find_left_max_node_val(root)
                root.left = self.deleteNode(root.left, root.val)
        return root
                
        
```