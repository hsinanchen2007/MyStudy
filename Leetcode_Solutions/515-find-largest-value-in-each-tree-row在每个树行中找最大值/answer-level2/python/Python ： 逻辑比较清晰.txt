思路：将每一层的值添加到[], 然后max([val,...]), 得到每一层的最大值，最后分别添加到res中，返回res

```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def largestValues(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if not root:
            return []
        res= []
        deque = collections.deque([root])
        while deque:
            child = []
            for _ in range(len(deque)):
                root = deque.popleft()
                child.append(root.val)
                if root.left:
                    deque.append(root.left)
                if root.right:
                    deque.append(root.right)
            res.append(max(child)) 
        return res
```



