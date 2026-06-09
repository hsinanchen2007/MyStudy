### 解题思路
没什么花里胡哨的，老老实实构造树

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> TreeNode:
        def build(left,right):
            if left > right:
                return None
            max_num = max(nums[left:right+1])
            idx = nums.index(max_num)
            root = TreeNode(max_num)
            root.left = build(left,idx-1)
            root.right = build(idx+1,right)
            return root
        
        root = build(0,len(nums)-1)
        return root
            
```