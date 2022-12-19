### 解题思路
本来决定应该利用一下搜索树的性质,但是暴力能过很难提起兴趣干别的

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def getAllElements(self, root1, root2):
        """
        :type root1: TreeNode
        :type root2: TreeNode
        :rtype: List[int]
        """
        #直接暴力读数然后排序看看,这种做法击败了48,6
        # """
        temp=[]
        def get_num(root):
            if root:
                temp.append(root.val)
            else:
                return
            get_num(root.left)
            get_num(root.right)
        get_num(root1)
        get_num(root2)
        temp.sort()
        return temp
        # """

        #既然是二叉搜索树,可不可以分别得到两个有序数组,然后再排一次序.但是暴力能过,突然不想尝试了,下一题
```