### 解题思路
这道题考察二叉树的层序遍历，需要记录的是队列中每层最后一个结点。时间复杂度为O(N),空间复杂度为O(N)。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        import queue
        # 层序遍历，队列中每层的最后一个元素
        q = queue.Queue()
        q.put(root)
        res = []
        while not q.empty():
            length = q.qsize()
            print(length)
            while length>0:
                node = q.get()
                print(node.val)
                if length==1:
                    res.append(node.val)
                if node.left:
                    q.put(node.left)
                if node.right:
                    q.put(node.right)
                length-=1
        return res
```