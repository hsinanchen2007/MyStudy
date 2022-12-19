### 解题思路
很多代码都是将二叉树完全遍历，存到数组（栈）中，然后根据k的索引，去找target。
这样有2个问题可以优化：（1）不需要完全遍历，递归可以提前结束  （2）不用使用额外的空间，只保存最终的target
### 代码

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def kthLargest(self, root: TreeNode, k: int) -> int:
        if not root: return []
        self.target=0
        self.index=k#指导找到target，同时控制递归结束
        def inorderTraversal(root):
            if self.index==0:return  #如果找到了，提前结束
            if not root:return 
            if root.right:
                inorderTraversal(root.right)
            self.index-=1
            if self.index==0:
                self.target=root.val
            if root.left:
                inorderTraversal(root.left)
        inorderTraversal(root)
        return self.target


```