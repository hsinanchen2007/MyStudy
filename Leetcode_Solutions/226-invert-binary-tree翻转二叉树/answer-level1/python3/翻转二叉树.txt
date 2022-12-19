### 解题思路
我的思路：我的递归解法和迭代解法
	

复杂度分析：                                                             
	• 时间复杂度：o(n)
	• 空间复杂度：o(n)

### 代码

```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        # 使用递归
        if not root:
            return None
        # root若存在,则反转其左右子节点
        root.left,root.right = root.right,root.left
        self.invertTree(root.left) # 左子树翻转
        self.invertTree(root.right) # 右子树翻转
        return root 
```
迭代：
```
class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        # 使用迭代, 队列辅助
        if not root:
            return None
        queue = [root]
        while queue:
            cur_node = queue.pop(0)
            if cur_node:
                cur_node.left,cur_node.right = cur_node.right,cur_node.left
                queue.extend([cur_node.left,cur_node.right])
        return root
```
