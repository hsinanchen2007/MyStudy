### 解题思路
二叉搜索树中序遍历是个有序的数组，我们只要比较当前节点和前序节点的差值就行了（后续节点和当前节点的差值也行），我们用preval记录前序节点的值，在当前节点的时候我们进行判断比较就行，思路还是简单的！！

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def getMinimumDifference(self, root: TreeNode) -> int:
       
        stack = []
        preval = -9999 # 这里初始化前一个节点
        res = float('inf')
        while root or stack:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            if preval >= 0: # 从第二个节点开始判断
                print(root.val-preval, res)
                if root.val - preval < res:
                    res = (root.val - preval)
            preval = root.val
            root = root.right
        return res

```