### 解题思路
中序遍历得到非严格递增序列，然后统计每个节点的值是否等于前一节点的值，如果频次=最大次数，则增加一个元素；如果频次超过了当前最大次数，则丢掉此前的元素，重新开始统计。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findMode(self, root: TreeNode) -> List[int]:
        
        max_time = 1
        curtime = 1
        prenode = float("inf")
        ans = []

        stack = [(root, 0)]
        while stack:
            node, flag = stack.pop()
            if node:
                if flag:
                    if node.val == prenode:
                        curtime += 1
                    else:
                        curtime = 1
                        prenode = node.val
                    if curtime == max_time:
                        ans.append(node.val)
                    if curtime > max_time:
                        ans = [node.val]
                        max_time = curtime
                else:
                    if node.right:
                        stack.append((node.right, 0))
                    stack.append((node, 1))
                    if node.left:
                        stack.append((node.left, 0))
        return ans
```