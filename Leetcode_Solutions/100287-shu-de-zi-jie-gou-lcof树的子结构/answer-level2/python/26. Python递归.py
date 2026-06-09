### 解题思路
这道题可以分成两个步骤：
（1）遍历A的所有节点
（2）以当前A的节点为根的子树与B进行比较。

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSubStructure(self, A, B):
        """
        :type A: TreeNode
        :type B: TreeNode
        :rtype: bool
        """
        if B is None:
            return False
        def judge(root_1, root_2):
            if root_2 is None:
                return True
            if root_1 is None:
                return False
            return root_1.val == root_2.val and judge(root_1.left, root_2.left) and judge(root_1.right, root_2.right)
        
        def get_res(root):
            if root is None:
                return False
            return judge(root, B) or get_res(root.left) or get_res(root.right)
        
        return get_res(A)
```