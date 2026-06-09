### 解题思路
bfs遍历一下，没啥好说的
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def getTargetCopy(self, original: TreeNode, cloned: TreeNode, target: TreeNode) -> TreeNode:
        import queue
        store = queue.Queue()
        if cloned.val == target.val:
            return cloned
        store.put(cloned)
        while not store.empty():
            tmp = store.get()
            if tmp.left:
                if tmp.left.val == target.val:
                    return tmp.left
                store.put(tmp.left)
            if tmp.right:
                if tmp.right.val == target.val:
                    return tmp.right
                store.put(tmp.right)
```