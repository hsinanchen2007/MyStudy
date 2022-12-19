### 解题思路
直接看代码

### 代码

```
python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

#递归
class Solution:
    def searchBST(self, root: TreeNode, val: int) -> TreeNode:
        if root==None:
            return root
        if root.val==val:
            return root
        if root.val>val:
            return self.searchBST(root.left,val)
        if root.val<val:
            return self.searchBST(root.right,val)

#循环迭代
class Solution:
    def searchBST(self, root: TreeNode, val: int) -> TreeNode:
        while root:
            if root.val==val:
                return root
            elif root.val>val:
                root = root.left
            else:
                root = root.right

        return None

#栈迭代
class Solution:
    def searchBST(self, root: TreeNode, val: int) -> TreeNode:
        stack = [root]
        while stack:
            tmp = stack.pop()
            if tmp == None:
                continue
            if tmp.val == val:
                return tmp
            elif tmp.val>val:
                stack.append(tmp.left)
            else:
                stack.append(tmp.right)
        return None
```