超出时间限制
```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def widthOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        list_ = [root]
        m = 1
        while True:
            newlist= []
            for node in list_:
                if node:
                    newlist.append(node.left)
                    newlist.append(node.right)
                else:
                    newlist.extend([None, None])
            
            if list(set(newlist)) == [None]:
                break
            i, j = 0, len(newlist) - 1
            while not newlist[i]:
                i += 1
            while not newlist[j]:
                j -= 1
            m = max(m, j - i + 1)
            
            list_ = newlist
            # print(list_)
            
        return m
```
更改
