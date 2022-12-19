### 解题思路
递归前初始化一个树节点当做root节点，先的找list中最大值，这个最大值是当前节点的val，然后初始化一个当前数组中最大值的left节点，将这个left节点传入下一次递归，寻找root节点左边的最大值为left节点的val(下一层递归中传入的left节点就成为了根节点)，right同理，最后返回根节点即可。

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def constructMaximumBinaryTree(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        pre = TreeNode(None)                  
        def find_max(ls,head):
            if ls:
                max_index = ls.index(max(ls))
                head.val = ls[max_index]
                left = TreeNode(None)
                head.left = find_max(ls[:max_index],left)
                right = TreeNode(None)
                head.right = find_max(ls[max_index+1:],right)
                return head
            else:
                return
        return find_max(nums,pre)
```