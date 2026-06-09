### 解题思路
我的思路：
中序遍历得到递增队列,对队列进行遍历,前后比较得到最小绝对值.
	

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
    def getMinimumDifference(self, root: TreeNode) -> int:
        def DFS_in(root):
            '''深度优先遍历--中序遍历的迭代写法'''
            if not root:
                return None
            stack = [root]  # 使用栈
            mark = 1  # 用来标记
            lists = []
            while stack:  # 当栈不为空时
                node = stack[-1]
                if node.left and mark == 1:
                    stack.append(node.left)
                else:
                    mark = 0
                    node = stack.pop()
                    lists.append(node.val)
                    if node.right:
                        stack.append(node.right)
                        mark = 1
            return lists
        lists = DFS_in(root)
        abs_min = float('inf')
        for i in range(len(lists)-1):
            abs_min = min(abs_min,abs(lists[i+1]-lists[i]))
        return abs_min

```