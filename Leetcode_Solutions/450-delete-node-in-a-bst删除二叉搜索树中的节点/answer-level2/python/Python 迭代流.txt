```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        dummy = TreeNode(float('-inf'))
        dummy.right = root
        root = dummy
        
        while root:
            child_str = 'root.left' if root.val > key else 'root.right'
            child = eval(child_str)
            if not child or child.val != key: # 继续搜索删除目标的父节点
                root = child
            else: # 已经找到删除目标的父节点 root 和目标 child
                if child.left is child.right: # 情况1.目标没有子节点
                    exec(f'{child_str} = None')
                elif not (child.left and child.right): # 情况2.目标只有左子或右子
                    exec(f'{child_str} = child.left or child.right')
                else: # 情况3.目标有左子和右子
                    parent = child
                    root = parent.right
                    
                    while root and root.left: # 搜索中序后继节点
                        parent, root = root, root.left
                        
                    child.val = root.val
                    side = 'right' if parent is child else 'left'
                    exec(f'parent.{side} = root.right')
                    
        return dummy.right
```
