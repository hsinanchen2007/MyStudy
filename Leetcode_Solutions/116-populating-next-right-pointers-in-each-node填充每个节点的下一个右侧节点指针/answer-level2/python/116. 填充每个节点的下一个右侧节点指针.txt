### 解题思路
**一定要注意完美二叉树的定义，要么该层没有，要么该层是满的；**
1. 若根节点为空，直接返回。
2. 否则将根节点的next值赋值为None；
3. 判断是否有下一层；
4. 有的话将下一层逐一连接；
### 代码

```python3
"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root:
            return root
        def dfs(ltree, rtree):
            ltree.next = rtree
            rtree.next = None
            if ltree.left:
                dfs(ltree.left, ltree.right)
                dfs(ltree.right, rtree.left)
                dfs(rtree.left, rtree.right)
        dfs(root, root)
        return root
 
```