```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def calculate_depth(self, s):
        # "1-2--3--4-5--6--7"
        cur, depth, num = 0, 0, ''
        res = []
        while cur <= len(s):
            if cur == len(s):
                res.append((TreeNode(int(num)), depth))
            elif s[cur] == '-':
                if num == '': depth += 1
                else:
                    res.append((TreeNode(int(num)), depth))
                    num, depth = '', 1
            else: num += s[cur]
            cur += 1
        return res


    def recoverFromPreorder(self, S: str) -> TreeNode:
        # preorder depth serach
        # node cnt [1, 1000]
        # stack = [(1, 0)]
        # (2, 1) -> 1, 0 左边
        # (3, 2) -> 2, 0 左边
        # (4, 3) -> (3, 2)左边
        # (5, 1) -> pop(4, 3), pop(3, 2) -> pop(2, 1) -> 1, 0 右边
        # (6, 2) -> (5, 1)左边
        # (7, 3) -> (6, 2)左边
        # return stack[0][0]

        # Time complexity: O(N)
        # Space complexity: O(N)
        
        if S == '': return None   # corner case
        depth_arr = self.calculate_depth(S)
        stack = []
        for a, b in depth_arr:
            if stack == []:
                stack.append((a, b))
                continue
            while stack and b <= stack[-1][1]: stack.pop()
            node = stack[-1][0]
            if not node.left: node.left = a
            else: node.right = a
            stack.append((a, b))
        return stack[0][0]
            




```