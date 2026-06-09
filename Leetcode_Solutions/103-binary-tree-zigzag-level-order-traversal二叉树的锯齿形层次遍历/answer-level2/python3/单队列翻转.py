```
class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        queue = []
        queue.append(root)
        cnt = 0
        res = []
        while len(queue) > 0:
            q_len = len(queue)
            child = []
            tmp = []
            for i in range(q_len):

                parent = queue.pop(0)
                tmp.append(parent.val)

                if parent.left:
                    child.append(parent.left)
                if parent.right:
                    child.append(parent.right)

            if cnt % 2 == 1:
                tmp.reverse()
            res.append(tmp)
            queue.extend(child)

            cnt += 1
        return res
```