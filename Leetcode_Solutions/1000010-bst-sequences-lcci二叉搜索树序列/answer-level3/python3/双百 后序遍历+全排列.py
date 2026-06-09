### 解题思路
双百 后序遍历+全排列

左右子树在保证各自顺序的前提下进行全排列

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def BSTSequences(self, root: TreeNode) -> List[List[int]]:

        def fullarray(left, right, curr, result):

            if not left and not right:
                result.append(curr)
                return
            elif left and not right:
                result.append(curr + left)
                return
            elif right and not left:
                result.append(curr + right)
                return 
            
            fullarray(left[1:], right, curr+[left[0]], result)
            fullarray(left, right[1:], curr+[right[0]], result)

        def LRN(root):

            if root:
                left = LRN(root.left)
                right = LRN(root.right)
                
                result = []
                for l in left:
                    for r in right:
                        fullarray(l, r, [root.val], result)

                return result
            else:
                return [[]]

        return LRN(root)
        

```