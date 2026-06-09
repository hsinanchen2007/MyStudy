### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

import collections
class Solution:
    def findDuplicateSubtrees(self, root: TreeNode) -> List[TreeNode]:
        p=[]
        count=collections.Counter()
        def array(node):
            if node is None:
                return '#'
            tup='{}{}{}'.format(node.val,array(node.left),array(node.right))
            count[tup]+=1
            if count[tup]==2:
                p.append(node)
            return tup
        array(root)
        return p







    
```