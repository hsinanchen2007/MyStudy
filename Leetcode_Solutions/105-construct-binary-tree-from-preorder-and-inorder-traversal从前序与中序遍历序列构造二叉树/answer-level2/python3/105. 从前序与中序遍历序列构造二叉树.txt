### 解题思路
借鉴106题的思路，关键在于有前序序列，说明是先深度构造左子树，与106题唯一不同之处在于这个。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        def constructTree(in_left,in_right):
            if in_left>in_right:
                return None
            val = preorder_reverse.pop()
            root = TreeNode(val)

            index = value2index[val]

            root.left = constructTree(in_left,index-1)
            root.right = constructTree(index+1,in_right)
            
            return root
            
        value2index = {val:i for i,val in enumerate(inorder)}
        preorder_reverse = preorder[::-1]
        return constructTree(0,len(inorder)-1)
```