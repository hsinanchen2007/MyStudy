### 解题思路
![UC截图20200103182346.png](https://pic.leetcode-cn.com/0452e150959cd36b0bafa9bc107f7d271c4b0fae24eef0f10374add54568959b-UC%E6%88%AA%E5%9B%BE20200103182346.png)


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pruneTree(self, root: TreeNode) -> TreeNode:
        # 判断以root为根的树的子树是否全为0
        def help(root):
            if not root:
                return
            if root.val == 1:
                return True
            return help(root.left) or help(root.right)
        
        #递归判断，如果左子树全为0，就删去左子树，右子树全为0，就删去右子树
        if not root:
            return
        if not help(root.left):
            root.left = None
        if not help(root.right):
            root.right = None
        if root.left:
            self.pruneTree(root.left)
        if root.right:
            self.pruneTree(root.right)
        return root

```