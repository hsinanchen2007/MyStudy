```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        # normal binary tree
        # find the k smallest number
        # heap => Time complexity: log(NlogK)
        # maximum heap => if val < heap[0] => heap.pop(0) => heap.push

        heap = []
        def put_heap(val):
            if len(heap) < k:
                heapq.heappush(heap, -val)
            elif val < -heap[0]:
                heapq.heappop(heap)
                heapq.heappush(heap, -val)

        def traverse_tree(node):
            if node is None: return
            put_heap(node.val)
            traverse_tree(node.left)
            traverse_tree(node.right)
        traverse_tree(root)
        return -heap[0]
        
```