### 解题思路
中序遍历后得到有序队列，双指针遍历队列输出结果，复杂度均为O(n)
### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def findTarget(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: bool
        """
        s = []
        def findallnodes(root):
            if root:
                findallnodes(root.left)
                s.append(root.val)
                findallnodes(root.right)
        findallnodes(root)
        start,end = 0, len(s)-1
        while start < end:
            if s[start] + s[end] < k:
                start += 1
            elif s[start] + s[end] > k:
                end -= 1
            else:
                return True
        return False


        
```