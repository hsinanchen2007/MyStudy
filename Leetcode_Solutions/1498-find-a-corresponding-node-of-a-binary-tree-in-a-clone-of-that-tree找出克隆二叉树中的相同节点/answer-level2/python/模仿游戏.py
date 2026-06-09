### 解题思路

一个结点在二叉树中的位置和前序遍历到它所需步数是一一对应的。

本解法利用该性质，可以工作在有重复值的树上。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def getTargetCopy(self, original: TreeNode, cloned: TreeNode, target: TreeNode) -> TreeNode:
        def dfs(root):
            nonlocal cnt
            nonlocal step
            if root is None:
                return
            else:
                step += 1
                if root is target:
                    print('found target at step %d' % step)
                    cnt = step
                else:
                    dfs(root.left)
                    dfs(root.right)
        
        def ddfs(root):
            nonlocal ttarget
            nonlocal step
            if root is None:
                return
            else:
                step += 1
                if step == cnt:
                    ttarget = root
                    print('found ttarget at step %d' % step)
                else:
                    ddfs(root.left)
                    ddfs(root.right)
        
        cnt = 0
        step = 0
        ttarget = None
        dfs(original)
        step = 0
        ddfs(cloned)
        return ttarget

```