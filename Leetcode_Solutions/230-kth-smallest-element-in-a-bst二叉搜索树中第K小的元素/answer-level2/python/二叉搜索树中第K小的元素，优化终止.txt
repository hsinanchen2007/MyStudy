### 解题思路
1、中序遍历
2、全局变量，计数count=k和最终返回的res
3、当count递归减小，等于0时，返回第k小的元素，
4、步骤3中，此处返回一次，只是返回至上一层递归，若上一层存在右子树，则任然会继续遍历，**因此需要再加入判断小于0时，任然跳出返回，则不会继续遍历右子树，达到优化的效果**

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):

，

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        def search(node):
            if not node:
                return
            search(node.left)
            self.count = self.count - 1
            if self.count == 0:
                self.res = node.val
                return
            elif self.count<0:
                return
            search(node.right)
        
        self.count = k
        self.res = None
        search(root)
        # print(self.count)
        return self.res

```