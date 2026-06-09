### 解题思路
官方题解写的不错，这里写一下自己的理解
![image.png](https://pic.leetcode-cn.com/dd5c215220fca0251bd09e70841cd816dd2a1f61a80d7259046e9c54de26d347-image.png)


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        if root is None:
            return 
        
        # 下面其实相当于是在重新构造二叉搜索树
        if root.val < key:
            root.right = self.deleteNode(root.right, key)
        elif root.val > key:
            root.left = self.deleteNode(root.left, key)
        else: # root.val == key
            if root.left is None and root.right is None:
                root = None
            elif root.right:
                root.val = self.successor(root)
                root.right = self.deleteNode(root.right, root.val)
            elif root.left:
                root.val = self.predecessor(root)
                root.left = self.deleteNode(root.left, root.val)
        return root


    def successor(self, root): # 后继节点
        root = root.right
        while root.left:
            root = root.left
        return root.val
        

    def predecessor(self, root): # 前驱节点
        root = root.left
        while root.right:
            root = root.right
        return root.val
```