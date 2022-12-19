```
# Definition for a binary tree node.
from collections import deque


class Solution:
    def listOfDepth(self, tree: TreeNode) -> List[ListNode]:
        ans = []
        queue = deque()
        queue.appendleft((tree, 1))
        d = {}
        while queue:
            t, dep = queue.pop()
            if dep not in d.keys():
                if dep - 1 in d.keys():
                    ans.append(d[dep - 1])
                d[dep] = ListNode(t.val)
            else:
                l = d[dep]
                while l.next:
                    l = l.next
                l.next = ListNode(t.val)
            if t.left:
                queue.appendleft((t.left, dep + 1))
            if t.right:
                queue.appendleft((t.right, dep + 1))
        ans.append(d[dep])
        return ans
```