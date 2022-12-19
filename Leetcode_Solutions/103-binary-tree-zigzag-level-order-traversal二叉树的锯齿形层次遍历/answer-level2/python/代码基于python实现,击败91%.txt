代码基于python实现,击败91%
```code
"""
解题思路：
 这道题和102的层次遍历很像，我们利用队列解决层次遍历，然后设置一个标志位
 第一次为1，就把temp append到res中，否则就是把temp[::-1] append到res中
"""


class Solution(object):
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        res = []
        if root is None:
            return res
        queue = [root]
        flag = 1
        while queue:
            size = len(queue)
            temp = []
            for x in range(size):
                node = queue.pop(0)
                if node.left is not None:
                    queue.append(node.left)
                if node.right is not None:
                    queue.append(node.right)
                temp.append(node.val)
            if flag == -1:
                temp = temp[::-1]
            res.append(temp)
            flag *= -1
        return res
```

```vim
更多leetcode解法更新在我的github和掘金上
如果我的代码对你有帮助，可不可以给我一个star
```
