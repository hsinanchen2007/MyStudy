

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: int
        """
        #递归解法
        if not root:
            return 0
        
        def Solutions(Root, sums):
            left = right = 0
            temp = [num + Root.val for num in sums] + [Root.val]
            if Root.left:
                left = Solutions(Root.left, temp)
            if Root.right:
                right = Solutions(Root.right, temp)
            
            return temp.count(sum) + left + right
        
        return Solutions(root, [])

        #使用栈的方法

        if not root:
            return 0

        stack = [(root,[root.val])]
        res = 0

        while stack:
            note, nums = stack.pop()
            res += nums.count(sum)
            if note.left:
                temp = [note.left.val + num for num in nums] + [note.left.val]
                stack.append((note.left,temp))
            
            if note.right:
                temp = [note.right.val + num for num in nums] + [note.right.val]
                stack.append((note.right,temp))
        
        return res
            





            

 

```