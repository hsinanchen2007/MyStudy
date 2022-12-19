### 解题思路
见注释

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        # 无值返回None
        if not preorder: return None
        # 构造根节点
        root = TreeNode(preorder[0])
        # 根节点入栈
        stack = [root]
        # 遍历根节点之外的所有节点值
        for val in preorder[1:]:
            # 以栈中的节点为父，列表中取出的为子节点
            father, child = stack[-1], TreeNode(val)
            if child.val < father.val:
                father.left = child
            else:
                # 如果父节点比子节点小，则找到最先的一个比子节点小的栈内节点（），作为父节点
                while stack and child.val > stack[-1].val:
                    father = stack.pop()
                father.right = child    
            # 子节点入栈，作为下一轮的父节点备选。
            stack.append(child)
        
        return root
```