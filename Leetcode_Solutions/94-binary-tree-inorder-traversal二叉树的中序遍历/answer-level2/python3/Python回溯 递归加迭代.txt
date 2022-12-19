# 递归
``` python []
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        out_list = []

        def backtrace(root=root):
            if not root:
                return
            backtrace(root.left)
            out_list.append(root.val)
            backtrace(root.right)

        backtrace()
        return out_list
```

# 迭代
``` python []
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
'''
Example
                  8
                 / \
                3   10
               / \    \
              1   6    14     中序遍历顺序 左父右
                 / \   /      1-3-4-6-7-8-10-13-14
                4   7 13       在自己理解一下 就清楚了
'''
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        out_list = []
        stack = [] #用栈来进行处理中序遍历
        while root or stack: #如果root遍历结束且stack也为空 说明处理完毕 结束
            while root: #当root存在 压栈 且查找左子树
                stack.append(root)
                root = root.left
            root=stack.pop() #弹栈
            out_list.append(root.val) #添加
            root = root.right #添加右子树
        return out_list
```