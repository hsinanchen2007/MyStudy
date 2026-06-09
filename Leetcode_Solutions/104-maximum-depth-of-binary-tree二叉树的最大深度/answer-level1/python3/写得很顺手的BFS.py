```
from collections import deque
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if root is None:return 0
        q = deque()
        q.append(root)
        cnt = 0
        while q:
            level_cnt = len(q)
            for _ in range(level_cnt): #还是要记录一下每一层的个数
                cur = q.popleft()
                if cur.left is not None:
                    q.append(cur.left)
                if cur.right is not None:
                    q.append(cur.right)
            cnt += 1 #每次出去完才+1  第一层root出来了才+1
        return cnt
```

bfs写的很顺手，递归的写着突然卡壳了。。。。