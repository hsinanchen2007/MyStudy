# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
"""
思路比较简单，大家一眼都能看出来。
用栈来转换递归的先序遍历，对于当前出栈元素有四种讨论，（都为空，(t[0非空，t[1]空))，(t[0]空，t[1]不空), (都不空)，前两种情况做相同的处理，都是直接continue，第二种情况需要将t[1]嫁接到t[0]处，第三种情况相加节点，并添加新的元组到栈中，添加规则不说了，太easy
"""

class Solution:
    def mergeTrees(self, t1: TreeNode, t2: TreeNode) -> TreeNode:
        if not t1:
            return t2
        stack = [(t1,t2)]
        while stack:
            t = stack.pop()
            if (not t[0] and not t[1]) or (t[0] and not t[1]):
                continue
            elif t[0] and t[1]:
                t[0].val += t[1].val
                if not t[0].left:
                    t[0].left = t[1].left
                else:
                    stack.append((t[0].left,t[1].left))
                if not t[0].right:
                    t[0].right = t[1].right
                else:
                    stack.append((t[0].right, t[1].right))
            elif not t[0] and t[1]:
                t[0] = t[1]

        return t1