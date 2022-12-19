### 解题思路
队列遍历

### 代码

```python3
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""
class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        if not root: return []
        ans = []
        deque = collections.deque([root])

        while deque:
            cur_level_len = len(deque)
            ans.append([])
            for i in range(cur_level_len):
                node = deque.popleft()
                if node:
                    ans[-1].append(node.val)
                    for child in node.children:
                        deque.append(child)
        
        return ans

```