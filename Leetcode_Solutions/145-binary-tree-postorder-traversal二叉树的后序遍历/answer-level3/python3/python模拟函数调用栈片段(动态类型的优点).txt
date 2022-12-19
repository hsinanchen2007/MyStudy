```python

# 递归版
class Solution:
    def postorderTraversal(self, root: TreeNode) -> [int]:
        result = []
        def dfs(root):
            if root:
                dfs(root.left)
                dfs(root.right)
                result.append(root.val)
        dfs(root)
        return result


# 迭代版直接将递归版的片段逆序，可以看到完全就是递归版的代码逆序版本
class Solution:
    def postorderTraversal(self, root: TreeNode) -> [int]:
        result = []
        stack = []

        stack.append(root)
        while len(stack) > 0:
            croot = stack.pop()
            if croot is not None:
                if type(croot) is int:       # 遇到append指令
                    result.append(croot)
                else:
                    stack.append(croot.val)  # 将result.append(root.val)当成栈片段放入
                    stack.append(croot.right)
                    stack.append(croot.left)
        return result
```