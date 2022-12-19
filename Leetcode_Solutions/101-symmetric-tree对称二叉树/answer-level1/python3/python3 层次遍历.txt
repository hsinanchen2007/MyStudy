### 解题思路
python3 速度击败91.23%，内存击败99.45%
思路：层次遍历，在遍历每层时判断该层是否对称

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        queue = []
        cur = [root]
        while cur:#while循环遍历每层
            current = []
            next_node = []
            for node in cur:#遍历当前层所有node
                if node:
                    current.append(node.val)
                    next_node.extend([node.left,node.right])
                else:
                    current.append(None)
            index1,index2 = 0,len(current)-1
            while index1 < index2:#判断当前层是否对称
                if current[index1] != current[index2]:
                    return False
                else:
                    index1 += 1
                    index2 -= 1
            cur = next_node
        return True

```