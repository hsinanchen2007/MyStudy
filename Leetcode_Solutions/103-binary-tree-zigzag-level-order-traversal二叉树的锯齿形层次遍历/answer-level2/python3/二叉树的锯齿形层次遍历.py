### 解题思路
我的思路：和上一道题相比，整体不变，只是变了添加的顺序。
	

复杂度分析：                                                             
	• 时间复杂度：o(n)
	• 空间复杂度：o(n)



### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        current = [root]
        result = []
        reverse = 0
        while current:
            cur_val = []
            next_layer = []
            for node in current:
                if node and reverse == 1:
                    cur_val.insert(0,node.val)
                    next_layer.extend([node.left,node.right])
                elif node and reverse == 0:
                    cur_val.append(node.val)
                    next_layer.extend([node.left,node.right])
            if reverse == 1:
                reverse = 0
            else:
                reverse = 1
            if cur_val:
                result.append(cur_val)
            current = next_layer
        return result

```