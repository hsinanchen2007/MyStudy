### 解题思路
我的思路：层次迭代遍历，维护两个变量：一个最小值，一个次小值；层次扫描若遇到比当前最小值大的数，则存为次小值，退出。
	

复杂度分析：                                                             
	• 时间复杂度：o(n)
	• 空间复杂度：o(n)
### 代码

```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findSecondMinimumValue(self, root: TreeNode) -> int:
        if not root:
            return None
        stack = [root]
        first_min = root.val
        second_min = float('inf')
        mark = 0
        while stack:
            next_layer = []
            stack.sort(key=lambda x:x.val)
            for node in stack:
                if node.left:
                    next_layer.append(node.left)
                if node.right:
                    next_layer.append(node.right)
                if node and node.val > first_min and node.val < second_min:
                    second_min = node.val
                    mark = 1
            stack = next_layer
        if mark:
            return second_min
        else:
            return -1
                


```