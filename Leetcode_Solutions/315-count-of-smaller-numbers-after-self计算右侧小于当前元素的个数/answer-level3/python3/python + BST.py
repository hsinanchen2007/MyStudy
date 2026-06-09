```python
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = self.right = None
        self.cnt = 1
        self.smaller = 0

class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        # binary search tree: O(NlogN -> N**2)
        # segment tree + cnt => accelerate: O(NlogN)
        # merge sort => O(NlogN)
    
        root = None
        res = []

        def insert(node, num):
            if node.val == num:
                node.cnt += 1
                return node.smaller
            elif num < node.val: # insert left
                node.smaller += 1
                if node.left == None:
                    node.left = TreeNode(num)
                    return 0
                else:
                    return insert(node.left, num)
            else:   # insert right
                if node.right == None:
                    node.right = TreeNode(num)
                    return node.cnt + node.smaller
                else:
                    return node.cnt + node.smaller + insert(node.right, num)

        for num in reversed(nums):
            if root == None:
                root = TreeNode(num)
                res.append(0)
            else:
                res.append(insert(root, num))
        return res[::-1]  
```