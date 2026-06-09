解题思路：用一个列表保存每一层的节点，对该层节点完成遍历后再保存下一层节点，依次循环，直至为空。

![image.png](https://pic.leetcode-cn.com/5c6d0c265e98dd898ea3fa75c79e7476a94baa315b63dfbd15dc4fbb0630571a-image.png)


```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []
        rootList = [root]
        ans = []
        while rootList:
            ans.append([node.val for node in rootList])
            tempList = []
            for node in rootList:
                if node.left:
                    tempList.append(node.left)
                if node.right:
                    tempList.append(node.right)
            rootList = tempList
        return ans
```
