为什么控制台的输出是正确的，提交后的输出是错误的？
![a17980c7168906600d9a8c52c07953a.png](https://pic.leetcode-cn.com/7edd1dcae656607702141b9af33f62f2b9f6d7afc3684415b5ce395bfbd79901-a17980c7168906600d9a8c52c07953a.png)
![c6d930252178feafcfed459531fee99.png](https://pic.leetcode-cn.com/10056ef2bc8f90b6e2f509a124a0acc8354ae0726dc9a56c4e833d1f9a525986-c6d930252178feafcfed459531fee99.png)
```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    dict = {}
    def findMode(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if root:
            self.dict[root.val] = 1 if root.val not in self.dict.keys() else self.dict[root.val] + 1
            if isinstance(root.left, TreeNode):
                self.findMode(root.left)
            if isinstance(root.right, TreeNode):
                self.findMode(root.right)
        return [i for i  in self.dict.keys() if self.dict[i] == max(self.dict.values())]
```
