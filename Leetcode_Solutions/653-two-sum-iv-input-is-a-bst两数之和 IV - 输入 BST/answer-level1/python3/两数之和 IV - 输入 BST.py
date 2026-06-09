### 解题思路
我的思路：二叉搜索树的中序遍历是一个递增序列，然后问题即可转化为：
在递增序列中，是否存在两个元素的和等于给定的目标结果。可用"双指针"遍历一遍即可求解。
	

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
    def findTarget(self, root: TreeNode, k: int) -> bool:
        lists = []
        def inOrder(root):
            if not root:
                return None
            inOrder(root.left)
            lists.append(root.val)
            inOrder(root.right)
        inOrder(root)
        start = 0
        end = len(lists)-1
        while start < end:
            current_sum = lists[start] + lists[end]
            if current_sum == k:
                return True
            elif current_sum < k:
                start += 1
            else:
                end -= 1
        return False
```