### 解题思路
这道题可以不需要额外开辟空间存储节点（不包括递归所需空间）即改变指针指向即可，以Tree 1作为基础进行修改，需要处理四种情况：
（1）t1为空t2不为空
（2）t2为空t1不为空
（3）t1 t2都为空
（4）t1 t2都不为空

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def mergeTrees(self, t1, t2):
        """
        :type t1: TreeNode
        :type t2: TreeNode
        :rtype: TreeNode
        """
        def get_res(t1, t2):
            if t1 is None and t2:
                return t2
            if t2 is None and t1:
                return t1
            if t1 is None and t2 is None:
                return None
            t1.val += t2.val
            t1.left = get_res(t1.left, t2.left)
            t1.right = get_res(t1.right, t2.right)
            return t1
        return get_res(t1, t2)
```