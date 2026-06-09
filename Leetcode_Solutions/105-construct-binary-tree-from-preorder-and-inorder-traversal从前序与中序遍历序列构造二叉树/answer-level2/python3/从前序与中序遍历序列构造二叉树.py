### 解题思路
emmm确实还不会...

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
        pre_idx = 0
        idx_map = {val:idx for idx,val in enumerate(inorder)}
        def helper(in_left = 0, in_right = len(inorder)):
            nonlocal pre_idx
            # 若preorder的头值下标等于inorder的头值下标,表示没有
            if in_left == in_right:
                return None
            # 若不等：
            root_val = preorder[pre_idx] # 找到preorder当前的头值
            root = TreeNode(root_val) # 创建头节点

            index = idx_map[root_val] # 找到对应的inorder等于头值的下标
            pre_idx += 1
            # 递归
            root.left = helper(in_left,index)
            root.right = helper(index+1,in_right)
            return root
        return helper()

```
写法二，效率较低：
```
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if not inorder:
            return None
        root_val = preorder[0]
        root = TreeNode(root_val)
        index = inorder.index(root_val)
        root.left = self.buildTree(preorder[1:index+1],inorder[:index])
        root.right = self.buildTree(preorder[index+1:],inorder[index+1:])
        return root
```
