```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isCousins(self, root, x, y):
        """
        :type root: TreeNode
        :type x: int
        :type y: int
        :rtype: bool
        : 思路： 层次遍历，对于每一层出现x和y计数，因为值唯一，计数为2时说明x, y 在这一层
        :  都出现，判断是不时同一个父节点
        """

        if not root:
            return False

        result = False
        queue = [root]

        while queue:
            xy_num = 0
            for i in range(len(queue)):
                item = queue.pop(0)
                if item.val == x or item.val == y:
                    xy_num += 1
                
                if item.left and item.right:  # 判断当前节点是不是x, y 的父节点，是返回False
                    if (item.left.val == x and item.right.val == y) or (item.left.val == y and item.right.val == x):
                        return False
                if item.left:
                    queue.append(item.left)
                if item.right:
                    queue.append(item.right)
 
                if xy_num == 2:  # 计数 为2时说明 x,y均出现
                    return True

        return False  
```
