
直接使用递归的方法，判断是否有root，没有就返回，有的话就放入之前准备好的数组当中，我觉得我的代码写的问题还挺多的，期待大佬们的纠正！

![WeChatad5d6fa0ad92f3e554d61b43b5fbb8a0.png](https://pic.leetcode-cn.com/21606046d6d57247e0ff1f54cf032217c9436f03d23e88a8f39b046470453518-WeChatad5d6fa0ad92f3e554d61b43b5fbb8a0.png)

```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def __init__(self):
        self.a = []

    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        self.PreOrder(p)
        cur_p = self.a
        self.a = []
        self.PreOrder(q)
        cur_q = self.a
        return cur_p == cur_q

    def PreOrder(self, root):
        if not root:
            self.a.append("a")
            return
        self.a.append(root.val)
        self.PreOrder(root.left)
        self.PreOrder(root.right)
```
