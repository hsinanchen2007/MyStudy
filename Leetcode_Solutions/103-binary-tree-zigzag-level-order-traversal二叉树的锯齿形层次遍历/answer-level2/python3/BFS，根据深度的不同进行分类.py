```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def zigzagLevelOrder(self, root):
        if root == None:
            return []

        now_node = root
        now_step = 0  # left
        list1 = [(now_node, now_step)]
        rs_step = 0
        rs = []
        dic = {}
        while list1:
            now_node, now_step = list1.pop(0)

            if dic.get(now_step) == None:
                dic[now_step] = [now_node.val]
            else:
                if now_step % 2 == 0:
                    dic[now_step].append(now_node.val)
                else:
                    dic[now_step].insert(0,now_node.val)

            if now_node.left:
                list1.append((now_node.left, now_step + 1))
            if now_node.right:
                list1.append((now_node.right, now_step + 1))

        for key in dic.keys():
            rs.append(dic[key])

        return rs
```
